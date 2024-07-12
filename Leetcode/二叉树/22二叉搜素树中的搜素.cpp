#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>

using namespace std;

class Binary_Tree{
    private:
        struct Node{
            int data;
            Node* left;
            Node* right;
            Node(int val):data(val),left(nullptr),right(nullptr){}
        };
        using Btree=Node*;
        Btree root;

    public:
        Binary_Tree():root(nullptr){}

        void insert(int val){
             insert(root,val);
        }

        void levelordertravel(){
            Btree cur=root;
            queue<Btree> q;
            q.push(cur);
            while (!q.empty())
            {
                cur=q.front();
                q.pop();
                cout<<cur->data<<" ";
                if(cur->left!=nullptr){
                    q.push(cur->left);
                }
                if(cur->right!=nullptr){
                    q.push(cur->right);
                }
            }
            cout<<endl;
            
        }
        void preordertravel(){
            Btree cur=root;
            stack<Btree> s;
            s.push(cur);
            while(!s.empty()){
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

        void Inordertravel(){
            Btree cur=root;
            stack<Btree> s;
            while(!s.empty() || cur!=nullptr){
                while (cur!=nullptr)
                {
                    s.push(cur);
                    cur=cur->left;
                }
                cur=s.top();
                s.pop();
                cout<<cur->data<<" ";
                cur=cur->right;
                
            }
            cout<<endl;
        }

        void postordertravel(){
            Btree cur=root;
            stack<Btree> s1;
            stack<Btree> s2;
            s1.push(cur);
            while(!s1.empty()){
                cur=s1.top();
                s1.pop();
                s2.push(cur);
                if(cur->left!=nullptr){
                    s1.push(cur->left);
                }
                if(cur->right!=nullptr){
                    s1.push(cur->right);
                }
            }
            while(!s2.empty()){
                cout<<s2.top()->data<<" ";
                s2.pop();
            }
            cout<<endl;
        }



    private:
        void insert(Btree& cur,int val){
            if(cur==nullptr){
                cur=new Node(val);
            }
            else if(val<cur->data){
                insert(cur->left,val);
            }
            else
            {
                insert(cur->right,val);
            }
        }
};


int main(){
    Binary_Tree tree;
    tree.insert(4);
    tree.insert(2);
    tree.insert(1);
    tree.insert(3);
    tree.insert(6);
    tree.insert(5);
    cout<<"层序遍历"<<endl;
    tree.levelordertravel();
    cout<<"前序遍历"<<endl;
    tree.preordertravel();
    cout<<"中序遍历"<<endl;
    tree.Inordertravel();
    cout<<"后序遍历"<<endl;
    tree.postordertravel();
    return 0;
}