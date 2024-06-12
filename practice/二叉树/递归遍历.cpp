#include<iostream>

using namespace std;

class BinaryBtree{
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
        BinaryBtree(){
            this->root=nullptr;
        }

        
};