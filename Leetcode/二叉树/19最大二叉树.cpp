#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>

using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
using Btree = Node*;


// 函数声明
void levelOrderTraversal(Btree root);
Btree constructMaximumBinaryTree(vector<int>& arr);

//所有路径
vector<string> binaryTreePaths(Btree root);
void traversal(Btree cur, vector<int>& path, vector<string>& result);


    


int main() {
    
    vector<int> v={3,2,1,6,0,5};
    Node* root=constructMaximumBinaryTree(v);
    cout<<"中序遍历"<<endl;
    levelOrderTraversal(root);
    cout<<"从根遍历到叶子结点"<<endl;
    vector<string> result=binaryTreePaths(root);
    for(auto kk:result){
        cout<<kk<<endl;
    }
    
    return 0;
}




void levelOrderTraversal(Btree root) {
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

Btree constructMaximumBinaryTree(vector<int>& arr){
    Btree newnode=new Node(0);
    if(arr.size()==1){
        newnode->data=arr[0];
        return newnode;
    }

    int maxValue=0;
    int maxValueIndex=0;
    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i]>maxValue){
            maxValue=arr[i];
            maxValueIndex=i;
        }
    }
    newnode->data=maxValue;

    if(maxValueIndex>0){
        vector<int> newVec(arr.begin(),arr.begin()+maxValueIndex);
        newnode->left=constructMaximumBinaryTree(newVec);
    }
    if (maxValueIndex<(arr.size()-1))
    {
        vector<int> newVec(arr.begin()+maxValueIndex+1,arr.end());
        newnode->right=constructMaximumBinaryTree(newVec);
    }

    return newnode;
}


vector<string> binaryTreePaths(Btree root){
    vector<string> result;
    vector<int> path;
    if(root==nullptr){
        return result;
    }
    traversal(root,path,result);
    return result;
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
