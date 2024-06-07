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

    void insert(vector<T>& v) {
        if (v.empty()) return; // handle empty vector

        root = new Node(v[0]);
        queue<Btree> q;
        q.push(root);

        int i = 1;
        while (i < v.size()) {
            Btree cur = q.front();
            q.pop();

            if (i < v.size()) {
                cur->left = new Node(v[i++]);
                q.push(cur->left);
            }

            if (i < v.size()) {
                cur->right = new Node(v[i++]);
                q.push(cur->right);
            }
        }
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

    bool compare(Btree left,Btree right){
        if(left!=nullptr && right==nullptr) return false;
        else if(left==nullptr && right!=nullptr) return false;
        else if(left==nullptr && right==nullptr) return true;
        else if(left->data!=right->data) return false;
        bool A=compare(left->left,right->right);
        bool B=compare(left->right,right->left);
        return A&&B;
    }
    bool isSymmetric(){
        if(root==nullptr){
            return true;
        }
        return this->compare(root->left,root->right);
    }


};

int main() {
    BTreeList<int> btree;
    int len = 0;
    cout << "请输入节点个数" << endl;
    cin >> len;
    vector<int> v(len);
    cout << "请输入" << len << "的具体值 例如（2 3 4 5）" << endl;
    for (int i = 0; i < v.size(); i++) {
        cin >> v[i];
    }
    btree.insert(v);
    cout << "层序遍历:";
    btree.levelOrderTraversal();
    cout << endl;
    bool result=btree.isSymmetric();
    if(result){
        cout<<"对称二叉树"<<endl;
    }else{
        cout<<"不是对称二叉树"<<endl;
    }


    return 0;
}
