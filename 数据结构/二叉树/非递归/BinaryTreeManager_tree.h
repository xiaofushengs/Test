#include<iostream>
#include<stack>
#include<queue>

using namespace std;

template<typename T>
class BinaryTree{
    private:
        struct Node{
            T data;
            Node* left;
            Node* right;
            Node(T val):data(val),left(nullptr),right(nullptr){}
        };
        using Btree=Node*;
        Btree root;

        
    public:
        BinaryTree(){
            this->root=nullptr;
        }

        void insert(T val){
            insert(root,val);
        }


        void inOrderTraversal() const{
            inOrderTraversal(root);
            cout<<endl;
        }

        void preOrderTraversal() const{
            preOrderTraversal(root);
            cout<<endl;
        }

        void levelOrderTraversal() const{
            Btree cuurent=root;
            queue<Btree> q;
            q.push(cuurent);
            while(!q.empty()){
                cuurent=q.front();
                q.pop();
                cout<<cuurent->data<<" ";
                if(cuurent->left!=nullptr){
                    q.push(cuurent->left);
                }
                if(cuurent->right!=nullptr){
                    q.push(cuurent->right);
                }
            }
            cout<<endl;
        }

        void postOrderTraversal() const{
            Btree ptree=root;
            if(!ptree){
                cout<<"tree is null"<<endl;
                return;
            }
            stack<Btree> s;
            stack<Btree> outcome;
            s.push(ptree);
            while(!s.empty()){
                Btree cuurent=s.top();
                s.pop();
                outcome.push(cuurent);

                if(cuurent->left){
                    s.push(cuurent->left);
                }
                if(cuurent->right){
                    s.push(cuurent->right);
                }
            }

            while(!outcome.empty()){
                cout<<outcome.top()->data<<" ";
                outcome.pop();
            }
            cout<<endl;
        }

    
    private:
        void insert(Btree& p,T val){
            if(p==nullptr){
                p=new Node(val);
            }
            else if(val<p->data){
                insert(p->left,val);
            }
            else{
                insert(p->right,val);
            }
        }

        void inOrderTraversal(const Btree& p) const{
            if(!p){
                cout<<"tree is null"<<endl;
                return;
            }

            stack<Btree> s;
            Btree current=p;

            while(current!=nullptr || !s.empty()){
                while(current!=nullptr){
                    s.push(current);
                    current=current->left;
                }
                current=s.top();
                s.pop();
                cout<<current->data<<" ";
                current=current->right;
            }
        }


        void preOrderTraversal(const Btree& p) const{
            if(p==nullptr){
                cout<<"tree is null"<<endl;
                return;
            }
            
            stack<Btree> s;
            s.push(p);

            while(!s.empty()){
                Btree cuurent=s.top();
                s.pop();
                cout<<cuurent->data<<" ";

                if(cuurent->right!=nullptr){
                    s.push(cuurent->right);
                }
                if(cuurent->left!=nullptr){
                    s.push(cuurent->left);
                }
                
            }            
        }

};