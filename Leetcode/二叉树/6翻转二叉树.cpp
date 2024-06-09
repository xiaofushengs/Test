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

    void swapBtree(){
        swapBtree(root);
    }

private:
    void prelOrderTraversal(const Btree& bt)const{
        Btree cur=bt;
        stack<Btree> s;
        s.push(cur);
        while (!s.empty())
        {
            cur=s.top();
            s.pop();
            cout<<cur->data<<" ";
            if(cur->right!=nullptr){
                s.push(cur->right);
            }
            if(cur->left!=nullptr){
                s.push(cur->left);
            }
        }
        cout<<endl;
    }

    void InOrderTraversal(const Btree& bt)const{
        if(root==nullptr){
            return;
        }
        Btree cur=root;
        stack<Btree> s;
        while (!s.empty()|| cur!=nullptr)
        {   
            while (cur!=nullptr)
            {
                s.push(cur);
                cur=cur->left;
            }

            cur=s.top();
            cout<<cur->data<<" ";
            s.pop();
            cur=cur->right;
        }
        cout<<endl;
    }

    void postOrderTraversal(const Btree& bt)const{
        if(bt==nullptr){
            return;
        }
        Btree cur=root;
        stack<Btree> s1,s2;
        s1.push(cur);
        while (!s1.empty())
        {   
            cur=s1.top();
            s1.pop();
            s2.push(cur);

            if(cur->left){
                s1.push(cur->left);
            }
            if(cur->right){
                s1.push(cur->right);
            }

        }
        while (!s2.empty())
        {
            cout<<s2.top()->data<<" ";
            s2.pop();
        }
        cout<<endl;
        
    }


    void swapBtree(Btree & bt){
        if(bt==nullptr){
            return;
        }
        swap(bt->left,bt->right);
        swapBtree(bt->left);
        swapBtree(bt->right);
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

    btree.swapBtree();
    cout << "交互后层序遍历:";
    btree.levelOrderTraversal();
    cout << endl;


    return 0;
}
