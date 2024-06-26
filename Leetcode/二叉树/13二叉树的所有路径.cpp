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

    vector<string> BinaryTreepath(){
        vector<string> result;
        vector<int> path;
        if(root==nullptr){
            return result;
        }
        traversal(root,path,result);
        return result;
    }

    

private:
    void traversal(Btree cur,vector<int>& path,vector<string>& result){
         path.push_back(cur->data);
         if(cur->left==nullptr && cur->right==nullptr){
            string spath;
            for (int i = 0; i < path.size()-1; i++)
            {
                  spath+=to_string(path[i]);
                  spath+="->";
            }
            spath+=to_string(path[path.size()-1]);
            result.push_back(spath);
            return;
         }
         if(cur->left){
            traversal(cur->left,path,result);
            path.pop_back();
         }
         if(cur->right){
            traversal(cur->right,path,result);
            path.pop_back();
         }
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

    cout << "�������:";
    btree.levelOrderTraversal();
    cout << endl;

    vector<string> v=btree.BinaryTreepath();
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<endl;
    }
    cout<<endl;
    
    return 0;
}
