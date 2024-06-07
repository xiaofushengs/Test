#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class BinaryTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(T val) : data(val), left(nullptr), right(nullptr) {}
    };
    using BTree = Node*;
    BTree root;

public:
    BinaryTree() : root(nullptr) {}

    void insert(T val) {
        insert(root, val);
    }

    // Ç°Ðò±éÀú
    void preOrderTraversal() const {
        preOrderTraversal(root);
        cout << endl;
    }
    
    //ÖÐÐò±éÀú
    void InOrderTraversal() const{
        InOrderTraversal(root);
        cout<<endl;
    }

    //ºóÐò±éÀú
    void postOrderTraversal() const{
        postOrderTraversal(root);
        cout<<endl;
    }

    //²ãÐò±éÀú
    void levelOrderTraversal() const{
        if(root==nullptr){
            return;
        }
        queue<BTree> q;
        q.push(root);
        while (!q.empty())
        {
           BTree current=q.front();
           q.pop();
           cout<<current->data<<" ";
           if(current->left!=nullptr){
                q.push(current->left);
           }
           if(current->right!=nullptr){
                q.push(current->right);
           }
        }
        cout<<endl; 
    }



private:
    void preOrderTraversal(const BTree& pTree) const {
        if (pTree) {
            cout << pTree->data << " ";
            preOrderTraversal(pTree->left);
            preOrderTraversal(pTree->right);
        }
    }

    void insert(BTree& p, T val) {
        if (p == nullptr) {
            p = new Node(val);
        } else if (val < p->data) {
            insert(p->left, val);
        } else {
            insert(p->right, val);
        }
    }

    void InOrderTraversal(const BTree& pTree) const{
          if (pTree) {
            InOrderTraversal(pTree->left);
            cout << pTree->data << " ";
            InOrderTraversal(pTree->right);
          }
    }

    void postOrderTraversal(const BTree& pTree) const{
         if (pTree) {
            postOrderTraversal(pTree->left);
            postOrderTraversal(pTree->right);
            cout << pTree->data << " ";
        }
    }
};

