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

    int sumLeftLeaves(){
        return sumLeftLeaves(root);
    }

    int sumRightLeaves(){
        return sumRightLeaves(root);
    }


    //找数的左下角的值
    int Maxdepth=INT_MIN;
    int result;
    void traversal_Tree(Btree root,int depth){
        if(root->left==nullptr && root->right==nullptr){
            if(depth>Maxdepth){
                Maxdepth=depth;
                result=root->data;
            }
            return;
        }
        if(root->left){
            depth++;
            traversal_Tree(root->left,depth);
            depth--;
        }
        if(root->right){
            depth++;
            traversal_Tree(root->right,depth);
            depth--;
        }
        return;
    }

    int findBottomLeftValue(){
        traversal_Tree(root,0);
        return result;
    }

   
private:
     int sumLeftLeaves(Btree& root){
        if(root==nullptr) return 0;
        if(root->left==nullptr && root->right==nullptr) return 0;
        
        int leftValue=sumLeftLeaves(root->left);
        if(root->left && !root->left->left && !root->left->right){
            leftValue=root->left->data;
        }

        int rightValue=sumLeftLeaves(root->right);

        int sum=leftValue+rightValue;
        return sum;
    }

    int sumRightLeaves(Btree& root){
        if(root==nullptr) return 0;
        if(root->left==nullptr && root->right==nullptr) return 0;

        int rightValue=sumRightLeaves(root->right);
        if(root->right && !root->right->left && !root->right->right){
            rightValue=root->right->data;
        }

        int leftValue=sumRightLeaves(root->left);

        int sum=rightValue+leftValue;

        return sum;
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
    cout<<"左叶子结点之和:"<<btree.sumLeftLeaves()<<endl;
    cout<<"右叶子结点之和:"<<btree.sumRightLeaves()<<endl;
    cout<<"左下角的值:"<<btree.findBottomLeftValue()<<endl;
    
    return 0;
}
