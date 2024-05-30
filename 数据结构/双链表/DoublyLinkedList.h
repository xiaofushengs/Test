#include<iostream>

using namespace std;

template<typename T>
class DoublyLinkedList{
    private:
        struct Node{
            T data;
            Node* front;
            Node* next;
            Node(T val):data(val),front(nullptr),next(nullptr){}
        };
        Node* head;
        Node* tail;
    
    public:
        DoublyLinkedList():head(nullptr),tail(nullptr){}

         // �������ݵ�β��
        void InsertBack(T value){
            Node* newnode = new Node(value);
            if(head == nullptr){
                head = tail = newnode;
            }
            else{
                tail->next = newnode;
                newnode->front = tail;
                tail = newnode;
            }
        }

        // �������ݵ�ͷ��
        void InsertFront(T value){
            Node* newnode = new Node(value);
            if(head == nullptr){
                head = tail = newnode;
            }
            else{
                head->front = newnode;
                newnode->next = head;
                head = newnode;
            }
        }

      // ��ͷ��β��ӡ
        void printAllBackward() const {
            Node* current = head;
            while(current != nullptr){
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }

        // ��β��ͷ��ӡ
        void printAllForward() const {
            Node* current = tail;
            while(current != nullptr){
                cout << current->data << " ";
                current = current->front;
            }
            cout << endl;
        }

        //ɾ��Ԫ��
        void remove(T value){
            Node* current=head;
            while(current!=nullptr && current->data!=value){
                current=current->next;
            }
            if(current==nullptr){
                cout<<"û�и�Ԫ��"<<endl;
                return;
            }
            if(current->front!=nullptr){
                current->front->next=current->next;
            }
            else{
                head=current->next;
            }

            if(current->next!=nullptr){
                current->next->front=current->front;
            }
            else{
                tail=current->front;
            }
            delete current;
        }

        ~DoublyLinkedList(){
            Node* current=head;
            while (current!=nullptr)
            {
                Node* p=current;
                current=current->next;
                delete p;
            }
            
        }
};