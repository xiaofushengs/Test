#include "TreeManager.h"

int main() {
    BinaryTree<int> bt;

    bt.insert(5);
    bt.insert(3);
    bt.insert(7);
    bt.insert(2);
    bt.insert(4);
    bt.insert(6);
    bt.insert(8);

    cout << "Pre-order traversal: ";
    bt.preOrderTraversal();
    cout << "IN-order traversal: ";
    bt.InOrderTraversal();
    cout << "post-order traversal: ";
    bt.postOrderTraversal();
    cout << "level-order traversal: ";
    bt.levelOrderTraversal();
    
    return 0;
}