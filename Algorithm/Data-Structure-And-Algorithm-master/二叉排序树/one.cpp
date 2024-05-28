#include<iostream>
using namespace std;

template <typename T>
class BinarySearchTree {
private:
    struct BTNode {
        T data;
        BTNode* pLchild;
        BTNode* pRchild;

        BTNode(T val) : data(val), pLchild(nullptr), pRchild(nullptr) {}
    };

    using BTree = BTNode*;
    BTree root;

    void insert(BTree& node, T val) {
        if (node == nullptr) {
            node = new BTNode(val);
        } else if (val < node->data) {
            insert(node->pLchild, val);
        } else if (val > node->data) {
            insert(node->pRchild, val);
        }
    }

    bool search(const BTree& node, T val) const {
        if (node == nullptr) {
            return false;
        } else if (val < node->data) {
            return search(node->pLchild, val);
        } else if (val > node->data) {
            return search(node->pRchild, val);
        } else {
            return true;
        }
    }

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

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(T val) {
        insert(root, val);
    }

    bool search(T val) const {
        return search(root, val);
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
};

int main() {
    BinarySearchTree<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << "前序遍历：";
    bst.pre_traverse();
    cout << "\n";

    cout << "中序遍历：";
    bst.in_traverse();
    cout << "\n";

    cout << "后序遍历：";
    bst.beh_traverse();
    cout << "\n";

    int searchValue = 60;
    if (bst.search(searchValue)) {
        cout << "找到值 " << searchValue << "\n";
    } else {
        cout << "未找到值 " << searchValue << "\n";
    }

    return 0;
}
