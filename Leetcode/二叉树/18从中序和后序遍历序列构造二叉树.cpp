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


// ��������
void levelOrderTraversal(Btree root);
Btree constructMaximumBinaryTree(vector<int>& arr);

//����·��
vector<string> binaryTreePaths(Btree root);
void traversal(Btree cur, vector<int>& path, vector<string>& result);

//��������ͺ���������������
Btree BuildTree(vector<int>& inorder,vector<int>& postorder);
Btree traversal_Tree(vector<int>& inorder,vector<int>& postorder);


    


int main() {
    
    vector<int> v_inorder={9,3,15,20,7};
    vector<int> v_postorder={9,15,7,20,3};
    Node* root=BuildTree(v_inorder,v_postorder);
    cout<<"�������"<<endl;
    levelOrderTraversal(root);
    cout<<"�Ӹ�������Ҷ�ӽ��"<<endl;
    vector<string> result=binaryTreePaths(root);
    for(auto kk:result){
        cout<<kk<<endl;
    }
    
    return 0;
}



//�������
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

//������������
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


//����
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


//����������

Btree BuildTree(vector<int>& inorder,vector<int>& postorder){
    if(inorder.size()==0 || postorder.size()==0){
        return nullptr;
    }
    return traversal_Tree(inorder,postorder);
}

Btree traversal_Tree(vector<int>& inorder,vector<int>& postorder){
    if(postorder.size()==0) return nullptr;

    int root_Data=postorder[postorder.size()-1];
    Btree root=new Node(root_Data);

    //Ҷ�ӽ��
    if(postorder.size()==1) return root;

    //�ҵ�����������и��
    int cutting_point;
    for ( cutting_point = 0; cutting_point < inorder.size(); cutting_point++)
    {
        if(inorder[cutting_point]==root_Data) break;
    }

    //�и���������
    vector<int> leftInorder(inorder.begin(),inorder.begin()+cutting_point);
    vector<int> rightInorder(inorder.begin()+cutting_point+1,inorder.end());

    //��������βԪ��
    postorder.resize(postorder.size()-1);
    //�и��������
    vector<int> leftPostorder(postorder.begin(),postorder.begin()+leftInorder.size());
    vector<int> rightPostorder(postorder.begin()+leftInorder.size(),postorder.end());

    root->left=traversal_Tree(leftInorder,leftPostorder);
    root->right=traversal_Tree(rightInorder,rightPostorder);

    return root;
    


}

