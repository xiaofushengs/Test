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

ListNode* Reverse(ListNode* head){
    ListNode* current=head;
    ListNode* pre=nullptr;
    ListNode* temp;
    while(current!=nullptr){
        temp=current->next;
        current->next=pre;
        pre=current;
        current=temp;
    }
    return pre;

}



int main(){
    vector<int> v={1,2,3,4,5};
    ListNode* head=createList(v);
    printElement(head);
    ListNode* head1=Reverse(head);
    printElement(head1);

}