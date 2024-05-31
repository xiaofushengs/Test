#include "BinaryTreeManager_tree.h"

int main(){
    BinaryTree<int> bt;
    bt.insert(5);
    bt.insert(3);
    bt.insert(7);
    bt.insert(2);
    bt.insert(4);
    bt.insert(6);
    bt.insert(8);
    bt.inOrderTraversal();
    bt.preOrderTraversal();
    bt.levelOrderTraversal();
    bt.postOrderTraversal();
}