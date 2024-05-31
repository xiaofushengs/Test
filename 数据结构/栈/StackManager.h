#include<iostream>
#include<string>

using namespace std;

template<typename T>
class StackLinkedList{
    private:
        struct Node{
            T data;
            Node* next;
            Node(T val):data(val),next(nullptr){}
        };
        Node* head;
        int size;
    
    public:
        StackLinkedList():head(nullptr),size(0){}

        ~StackLinkedList(){
            while(!isEmpty()){
                Top();
            }
        }
        void Push(T value){
            Node* newnode=new Node(value);
            newnode->next=head;
            head=newnode;
            size++;
        }

        T Top(){
            return head->data;
        }

        bool isEmpty(){
            if(head==nullptr){
                return true;
            }
            return false;
        }

        void Pop(){
            if(isEmpty()){
                cout<<"list is null"<<endl;
                return;
            }
            Node* p=head;
            head=head->next;
            delete p;
            size--;
        }

        int getsize(){
            return size;
        }

        

};