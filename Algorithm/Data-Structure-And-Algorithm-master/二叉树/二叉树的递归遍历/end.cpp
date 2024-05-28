#include <iostream>
#include <memory>
#include <queue>

using namespace std;

template <typename T>
class BinaryTree {
private:
    struct BTNode {
        T data;
        BTNode* pLchild;
        BTNode* pRchild;

        BTNode(T val) : data(val), pLchild(nullptr), pRchild(nullptr) {}
    };

    using BTree = BTNode*;
    BTree root;

public:
    BinaryTree() : root(nullptr) {}

    void create_dynamic_tree() {
        T data;
        cout << "Enter root node data (e.g., 'A'): ";
        cin >> data;

        root = new BTNode(data);
        queue<BTree> nodeQueue;
        nodeQueue.push(root);

        while (!nodeQueue.empty()) {
            BTree current = nodeQueue.front();
            nodeQueue.pop();

            T leftData, rightData;
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
    }

    void pre_traverse() const {
        pre_traverse(root);
    }

    void in_traverse() const {
        in_traverse(root);
    }

    void beh_traverse() const {
        beh_traverse(root);
    }

private:
    void pre_traverse(const BTree& pTree) const {
        if (pTree) {
            cout << pTree->data << " ";
            pre_traverse(pTree->pLchild);
            pre_traverse(pTree->pRchild);
        }
    }

    void in_traverse(const BTree& pTree) const {
        if (pTree) {
            in_traverse(pTree->pLchild);
            cout << pTree->data << " ";
            in_traverse(pTree->pRchild);
        }
    }

    void beh_traverse(const BTree& pTree) const {
        if (pTree) {
            beh_traverse(pTree->pLchild);
            beh_traverse(pTree->pRchild);
            cout << pTree->data << " ";
        }
    }
};

int main() {
    BinaryTree<char> tree;
    tree.create_dynamic_tree();

    cout << "递归实现前序遍历结果：";
    tree.pre_traverse();
    cout << "\n";

    cout << "递归实现中序遍历结果：";
    tree.in_traverse();
    cout << "\n";

    cout << "递归实现后序遍历结果：";
    tree.beh_traverse();
    cout << "\n";

    return 0;
}
