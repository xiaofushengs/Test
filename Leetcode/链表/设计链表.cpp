#include<iostream>

using namespace std;

class MyLinkedList{
    private:
        struct Node{
            int data;
            Node* next;
            Node(int val):data(val),next(nullptr){}
        };
        Node* head;
        int size=0;

    public:
        MyLinkedList(){
            head=nullptr;
            size=0;
        }

        //头插
        void addAtHead(int value){
             Node* newnode=new Node(value);
             newnode->next=head;
             head=newnode;
             size++;
        }

        //尾插
        void addAtTail(int value){
            Node* current=head;
            while(current->next!=nullptr){
                current=current->next;
            }
            Node* newnode=new Node(value);
            current->next=newnode;
            size++;
            
        }

        void printListed()const{
            Node* current=head;
            while (current!=nullptr)
            {
                cout<<current->data<<"->";
                current=current->next;
            }
            cout<<"null"<<endl;
        }

        void deleteAtindex(int index){
            if(index>=size){
                cout<<"数组没有那么长"<<endl;
                return;
            }
            if(index==0){
                Node* p=head;
                head=head->next;
                delete p;
                size--;
                return;
            }

            Node* current=head;
            int k=1;
            while(current->next!=nullptr){
                if(index==k){
                    Node* p=current->next;
                    current->next=p->next;
                    delete p;
                    size--;
                    return;
                }
                k++;
                current=current->next;
            }  

               
        }


        int getsize()const{
            return size;
        }

        void AddAtindex(int index,int value){
            if(index>=size){
                cout<<"超过数组长度"<<endl;
                return;
            }

            if(size==0 || index==0){
                this->addAtHead(value);
                size++;
                return;
            }
            if(index==size-1){
                this->addAtTail(value);
                size++;
                return;
            }
            if(index<size-1 && index>0){
                int i=1;
                Node* current=head;
                while(current->next!=nullptr){
                    if(index==i){
                        Node* p=new Node(value);
                        swap(current->next->data,p->data);
                        p->next=current->next->next;
                        p=current->next->next;
                        return;
                        size++;
                    }
                }
                
                
            }



        }
};

int main(){
    MyLinkedList linkelist;
    linkelist.addAtHead(1);
    linkelist.addAtTail(3);
    linkelist.addAtHead(2);
    linkelist.addAtHead(2);
    linkelist.printListed();
    linkelist.AddAtindex(0,100);
    linkelist.printListed();
    linkelist.AddAtindex(5,100);
    linkelist.printListed();
    linkelist.AddAtindex(1,1000);
    linkelist.printListed();
    

    return 0;
}