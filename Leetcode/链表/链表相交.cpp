#include<iostream>
#include<vector>
#include<sstream>

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



vector<int> ParseInput(const string& input){
    vector<int> result;
    stringstream ss(input);
    string token;
    while (getline(ss,token,','))
    {
        result.push_back(stoi(token));
    }
    return result;
    
}

Node* getIntersectionNode(Node* headA,Node* headB){
    Node* curA=headA;
    Node* curB=headB;
    int lenA=0,lenB=0;
    while (curA!=nullptr)
    {
        lenA++;
        curA=curA->next;
    }

    while (curB!=nullptr)
    {
        lenB++;
        curB=curB->next;
    }

    //重新回去
    if(lenA<lenB){
        curA=headB;
        curB=headA;
        swap(lenA,lenB);
    }else{
        curA=headA;
        curB=headB;
    }
    int gap=lenA-lenB;

    while(gap--){
        curA=curA->next;
    }

    while (curA!=nullptr)
    {
        if(curA->data==curB->data){
            return curA;
        }
        curA=curA->next;
        curB=curB->next;
    }
    return nullptr;
    
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


int main(){
    string input;
    cout<<"请输入A链表各个数值 例如（1，2，3，4）"<<endl;
    getline(cin,input);
    vector<int> v1=ParseInput(input);
    Node* headA=create(v1);

    string input1;
    cout<<"请输入B链表各个数值 例如（1，2，3，4）"<<endl;
    getline(cin,input1);
    vector<int> v2=ParseInput(input1);
    Node* headB=create(v2);

    printListed(headA);
    printListed(headB);

    Node* headC=getIntersectionNode(headA,headB);

    if(headC){
        printListed(headC);
    }else{
        cout<<"没有相交元素"<<endl;
    }
    
    return 0;
}