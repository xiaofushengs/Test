
#include <iostream>
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

ListNode* remove(ListNode* head,int value){
    
    while (head!=nullptr && head->val==value)
    {   
        ListNode* current=head;
        head=head->next;
        delete current;
    }

    ListNode* cur=head;
    while(cur!=nullptr && cur->next!=nullptr){
        if(cur->next->val==value){
            ListNode*p =cur->next;
            cur->next=p->next;
            delete p;
        }else{
            cur=cur->next;
        }
    }
    return head;
    
    
}

int main(){
    vector<int> vals = {1, 2, 6, 3, 4, 5, 6};
    ListNode* head = createList(vals);
    printElement(head);
    ListNode* head1=remove(head,6);
    printElement(head1);
}