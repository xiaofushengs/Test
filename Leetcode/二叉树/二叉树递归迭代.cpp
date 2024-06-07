#include<iostream>
#include<string>
#include<vector>
#include<queue>

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

    void prelOrderTraversal()const{
        prelOrderTraversal(root);
        cout<<endl;
    }

    void InOrderTraversal()const{
        InOrderTraversal(root);
        cout<<endl;
    }

    void postOrderTraversal()const{
        postOrderTraversal(root);
        cout<<endl;
    }

private:
    void prelOrderTraversal(const Btree& bt)const{
        if(bt){
            cout<<bt->data<<" ";
            prelOrderTraversal(bt->left);
            prelOrderTraversal(bt->right);
        }
        
    }

    void InOrderTraversal(const Btree& bt)const{
        if(bt){
            InOrderTraversal(bt->left);
            cout<<bt->data<<" ";
            InOrderTraversal(bt->right);
        }
    }

    void postOrderTraversal(const Btree& bt)const{
        if(bt){
            postOrderTraversal(bt->left);
            postOrderTraversal(bt->right);
            cout<<bt->data<<" ";
        }
    }


};

int main() {
    BTreeList<char> btree;
    int len = 0;
    cout << "请输入节点个数" << endl;
    cin >> len;
    vector<char> v(len);
    cout << "请输入" << len << "的具体值 例如（2 3 4 5）" << endl;
    for (int i = 0; i < v.size(); i++) {
        cin >> v[i];
    }
    btree.insert(v);
    cout << "层序遍历:";
    btree.levelOrderTraversal();
    cout << endl;

    cout<<"前序遍历:";
    btree.prelOrderTraversal();

    cout<<"中序遍历:";
    btree.InOrderTraversal();

    cout<<"后序遍历:";
    btree.postOrderTraversal();




    return 0;
}
