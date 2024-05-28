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

// 前序遍历的递归实现
void pre_traverse(const BTree& pTree) {
    if (pTree) {
        cout << pTree->data << " ";
        pre_traverse(pTree->pLchild);
        pre_traverse(pTree->pRchild);
    }
}

// 中序遍历的递归实现
void in_traverse(const BTree& pTree) {
    if (pTree) {
        in_traverse(pTree->pLchild);
        cout << pTree->data << " ";
        in_traverse(pTree->pRchild);
    }
}

// 后序遍历的递归实现
void beh_traverse(const BTree& pTree) {
    if (pTree) {
        beh_traverse(pTree->pLchild);
        beh_traverse(pTree->pRchild);
        cout << pTree->data << " ";
    }
}

int main() {
    BTree pTree = create_dynamic_tree();

    cout << "递归实现前序遍历结果：";
    pre_traverse(pTree);
    cout << "\n";

    cout << "递归实现中序遍历结果：";
    in_traverse(pTree);
    cout << "\n";

    cout << "递归实现后序遍历结果：";
    beh_traverse(pTree);
    cout << "\n";

    return 0;
}
