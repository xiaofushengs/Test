#include <iostream>
#include <memory>
#include <queue>

using namespace std;

struct BTNode {
    char data;
    BTNode* pLchild;
    BTNode* pRchild;

    BTNode(char val) : data(val), pLchild(nullptr), pRchild(nullptr) {}
};

using BTree = BTNode*;

BTree create_dynamic_tree() {
    char data;
    cout << "Enter root node data (e.g., 'A'): ";
    cin >> data;

    BTree root = new BTNode(data);
    queue<BTree> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty()) {
        BTree current = nodeQueue.front();
        nodeQueue.pop();

        char leftData, rightData;
        cout << "Enter left child of " << current->data << " (enter '.' if no left child): ";
        cin >> leftData;
        if (leftData != '.') {
            current->pLchild = new BTNode(leftData);
            nodeQueue.push(current->pLchild);
        }

        cout << "Enter right child of " << current->data << " (enter '.' if no right child): ";
        cin >> rightData;
        if (rightData != '.') {
            current->pRchild = new BTNode(rightData);
            nodeQueue.push(current->pRchild);
        }
    }

    return root;
}

// ǰ������ĵݹ�ʵ��
void pre_traverse(const BTree& pTree) {
    if (pTree) {
        cout << pTree->data << " ";
        pre_traverse(pTree->pLchild);
        pre_traverse(pTree->pRchild);
    }
}

// ��������ĵݹ�ʵ��
void in_traverse(const BTree& pTree) {
    if (pTree) {
        in_traverse(pTree->pLchild);
        cout << pTree->data << " ";
        in_traverse(pTree->pRchild);
    }
}

// ��������ĵݹ�ʵ��
void beh_traverse(const BTree& pTree) {
    if (pTree) {
        beh_traverse(pTree->pLchild);
        beh_traverse(pTree->pRchild);
        cout << pTree->data << " ";
    }
}

int main() {
    BTree pTree = create_dynamic_tree();

    cout << "�ݹ�ʵ��ǰ����������";
    pre_traverse(pTree);
    cout << "\n";

    cout << "�ݹ�ʵ��������������";
    in_traverse(pTree);
    cout << "\n";

    cout << "�ݹ�ʵ�ֺ�����������";
    beh_traverse(pTree);
    cout << "\n";

    return 0;
}
