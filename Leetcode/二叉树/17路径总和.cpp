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


    //路径总和
    bool hasPathSum(int sum){
        if(root==nullptr) return false;
        return traversal_Btree(root,sum-root->data);
    }

   
private:
    int traversal_Btree(Btree cur,int count){
        if(!cur->left && !cur->right && count==0) return true;
        if(!cur->left && !cur->right) return false;

        if(cur->left){
            count-=cur->left->data;
            if(traversal_Btree(cur->left,count)) return true;
            count+=cur->left->data;
        }

        if(cur->right){
            count-=cur->right->data;
            if(traversal_Btree(cur->right,count)) return true;
            count+=cur->right->data;
        }
        return false;
    }

     
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
    btree.insert(11);
    btree.insert(6);
    btree.insert(12);
    btree.insert(3);
    btree.insert(9);
    btree.insert(1);
    btree.insert(4);
    btree.insert(8);
    btree.insert(10);
    btree.insert(7);

    cout << "层序遍历:";
    btree.levelOrderTraversal();
    cout << endl;

    vector<string> v=btree.BinaryTreepath();
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<endl;
    }
    cout<<endl;
    cout<<"输入总路径长度:";
    int sum=0;
    cin>>sum;
    bool reusl=btree.hasPathSum(sum);
    if(reusl){
        cout<<"存在此路径"<<endl;
    }else{
        cout<<"不存在此路径"<<endl;
    }
    
    return 0;
}
