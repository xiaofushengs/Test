#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val):data(val),next(nullptr){}
};

Node* create(vector<int> &v){
    if(v.empty()){
        return nullptr;
    }
    Node* head=new Node(v[0]);
    Node* current=head;
    for (size_t i = 1; i < v.size(); i++)
    {
        current->next=new Node(v[i]);
        current=current->next;
    }
    return head;
}

void printListed(Node* head){
    Node* current=head;
    while (current!=nullptr)
    {
        cout<<current->data<<"->";
        current=current->next;
    }
    cout<<"nullptr"<<endl;
}

Node* removeNthFromEnd(Node* head,int n){
    Node* VirtualHead=new Node(0);
    VirtualHead->next=head;
    Node* fast=VirtualHead;
    Node* slow=VirtualHead;
    while (n-- && fast!=nullptr)
    {
        fast=fast->next;
    }
    fast=fast->next;
    while (fast!=nullptr)
    {
        slow=slow->next;
        fast=fast->next;
    }
    Node* temp=slow->next;
    slow->next=temp->next;
    delete temp;

    return VirtualHead->next;
}

int main(){
    int len=0;
    cout<<"请输入链表个数"<<endl;
    cin>>len;
    vector<int> v(len);
    cout<<"请输入下面链表具体值"<<endl;
    for (int i = 0; i < v.size(); i++)
    {
        cin>>v[i];
    }
    Node* head=create(v);
    printListed(head);
    int ElementNum=0;
    cout<<"请输入你要删除元素的下标  倒数第N个节点"<<endl;
    cin>>ElementNum;
    
    Node* head1=removeNthFromEnd(head,ElementNum);
    printListed(head1);
}