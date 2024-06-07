#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

template<typename T>
class BTreeList {

private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(T val) : data(val), left(nullptr), right(nullptr) {}
    };
    using Btree = Node*;
    Btree root;

public:
    BTreeList() : root(nullptr) {}

    void insert(T val){
        insert(root, val);
    }

    void levelOrderTraversal() const {
        if (root == nullptr) {
            return;
        }

        Btree cur = root;
        queue<Btree> q;
        q.push(cur);
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            cout << cur->data << " ";
            if (cur->left != nullptr) {
                q.push(cur->left);
            }
            if (cur->right != nullptr) {
                q.push(cur->right);
            }
        }
        cout << endl;
    }

    int getBtreeMinHeigth(){
        return getBtreeMinHeigth(root);  
    }

private:
    int getBtreeMinHeigth(Btree bt){  
        if(bt==nullptr){
            return 0;
        }
        int leftHeight=getBtreeMinHeigth(bt->left);
        int rightHeight=getBtreeMinHeigth(bt->right);
        if(bt->left==nullptr && bt->right!=nullptr){
            return 1+rightHeight;
        }
        if(bt->left!=nullptr && bt->right==nullptr){
            return 1+leftHeight;
        }
        return 1+min(leftHeight,rightHeight);
    }

    void insert(Btree &bt, T val){
        if(bt == nullptr){
            bt = new Node(val);
        } else if(val <= bt->data){
            insert(bt->left, val);
        } else {
            insert(bt->right, val);
        }
    }
};

int main() {
    BTreeList<int> btree;
    for(int i = 5; i <= 10; i++){
        btree.insert(i);
    }
    for (int i = 0; i < 3; i++){
        btree.insert(i);
    }

    cout << "层序遍历:";
    btree.levelOrderTraversal();
    cout << endl;
    cout << "树的最小深度:" << btree.getBtreeMinHeigth() << endl;

    return 0;
}
