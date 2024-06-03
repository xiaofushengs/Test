#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

void printElement(ListNode* list){
     ListNode* cuurent=list;
     while(cuurent!=nullptr){
        cout<<cuurent->val<<" ";
        cuurent=cuurent->next;
     }
     cout<<endl;
}

ListNode* swapPair(ListNode* head){
    ListNode* dummyHead =new ListNode(0);
    dummyHead->next=head;
    ListNode* cur=dummyHead;
    while(cur->next!=nullptr && cur->next->next!=nullptr){
        ListNode* p=cur->next;
        ListNode* temp=cur->next->next->next;
        cur->next=p->next;
        cur->next->next=p;
        cur->next->next->next=temp;
        cur=cur->next->next;
    }
    ListNode* result=dummyHead->next;
    delete dummyHead;
    return result;
}

int main(){
    vector<int> v={1,2,3,4,5};
    ListNode* head=createList(v);
    printElement(head);
    ListNode* head1=swapPair(head);
    printElement(head1);

}