#include<iostream>
#include<vector>
#include<string>
#include<queue>
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
        }



    private:
        void insert(Btree cur,int val){
            if(cur==nullptr){
                cur=new Node(val);
            }
            if(val<cur->data){
                insert(cur->left,val);
            }
            else
            {
                insert(cur->right,val);
            }
        }
};