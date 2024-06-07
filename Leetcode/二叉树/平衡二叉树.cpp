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

    int isBalaceTree()const{
        return isBalaceTree(root);
    }

private:
    int isBalaceTree(const Btree bt)const{
        if(bt==nullptr){
            return 0;
        }
        int leftHeight=isBalaceTree(bt->left);
        if(leftHeight==-1) return -1;
        int rightHeight=isBalaceTree(bt->right);
        if(rightHeight==-1) return -1;
        return abs(leftHeight-rightHeight)>1 ? -1:1+max(leftHeight,rightHeight);
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
    btree.insert(8);
    btree.insert(6);
    btree.insert(9);
    btree.insert(3);
    btree.insert(7);
    btree.insert(1);
    btree.insert(4);

    cout << "层序遍历:";
    btree.levelOrderTraversal();
    cout << endl;
    
    int result=btree.isBalaceTree();
    if(result>0){
        cout<<"该树为平衡数"<<endl;
    }else{
        cout<<"No"<<endl;
    }
   
    return 0;
}
