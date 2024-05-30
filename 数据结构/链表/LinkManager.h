#include<iostream>
#include<string>
using namespace std;

template<typename T>
class LinkedList{
   private:
     struct Node{
        T data;
        Node* next;
        Node():next(nullptr){}
        Node(T val):data(val),next(nullptr){}
     };
     Node* head;
     int size;

   public:
      LinkedList(){
         head=new Node();
         size=0;
      }
      ~LinkedList(){
         Node* cuurent=head;
         while (cuurent!=nullptr)
         {
            Node* p=cuurent;
            cuurent=cuurent->next;
            delete p;
         }
         
      }

      //插入数据
      void Insert(T val){
         Node* current=head;
         while(current->next!=nullptr){
            current=current->next;
         }
         current->next=new Node(val);
         size++;
      }

      //打印数据
      void printLinkedlist()const{
         Node* cuurent=head->next;
         while(cuurent!=nullptr){
            cout<<cuurent->data<<" ";
            cuurent=cuurent->next;
         }
         cout<<endl;
      }


      //删除数据
      void DeleteNode(T val){
         if(isEmpty()){
            cout<<"链表为空 无法删除数据"<<endl;
            return;
         }
         Node* current=head;
         while(current->next!=nullptr){
            if(current->next->data==val){
               Node* p=current->next;
               current->next=p->next;
               size--;
               delete p;
            }
            current=current->next;
         }
         
      }

      //获取链表长度
      int Getsize()const{
         return size;
      }

      bool isEmpty()const{
         if(size==0){
            return true;
         }
         return false;
      }
   
};