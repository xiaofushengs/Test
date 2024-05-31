#include<iostream>
#include<string>

using namespace std;

template<typename T>
class QueueLinkedList{
    private:
        struct Node{
            T data;
            Node* next;
            Node(T val):data(val),next(nullptr){}
        };
        Node* head;
        Node* tail;
        int size;

    public:
        QueueLinkedList(){
            this->head=nullptr;
            this->tail=nullptr;
            this->size=0;
        }

        void enqueue(T val){
            Node* newnode=new Node(val);
            if(tail==nullptr){
                head=tail=newnode;
            }else{
                tail->next=newnode;
                tail=newnode;
            }
            size++;
        }

        bool isEmpty()const{
            if(head==nullptr){
                return true;
            }
            return false;
        }

        T Top()const{
            return head->data;
        }

        void dequeue(){
            if(isEmpty()){
                cout<<"queue is null"<<endl;
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

        T front()const{
            return head->data;
        }

        T back()const{
            return tail->data;
        }
};