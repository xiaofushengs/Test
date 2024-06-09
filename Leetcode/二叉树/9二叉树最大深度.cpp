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

    int getBtreeHeigth(){
        return getBtreeHeigth(root);  
    }

private:
    int getBtreeHeigth(Btree bt){  
        if(bt == nullptr){  
            return 0;
        }
        int leftHeight = getBtreeHeigth(bt->left);
        int rightHeight = getBtreeHeigth(bt->right);

        return 1 + max(leftHeight, rightHeight);
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
    cout << "树的最大深度:" << btree.getBtreeHeigth() << endl;

    return 0;
}
