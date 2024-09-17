#include <iostream>
#include <vector>

using namespace std;

class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node* head;

public:
    LinkedList() : head(nullptr) {}
    
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void Insert_Linked(const vector<int>& v) {
        if (v.empty()) {
            cout << "Vector is empty, nothing to insert." << endl;
            return;
        }
        head = new Node(v[0]);
        Node* current = head;
        for (size_t i = 1; i < v.size(); i++) {
            current->next = new Node(v[i]);
            current = current->next;
        }
        cout << "插入成功" << endl;
    }

    void printLike() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << "->";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    void deleteLink(int val) {
        while (head != nullptr && head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        Node* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->next->data == val) {
                Node* temp = current->next;
                current->next = temp->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
        cout << "删除成功" << endl;
    }

    void reverse(){
        Node* q=nullptr;
        Node* p=head;
        while (p!=nullptr)
        {
            Node* current=p->next;
            p->next=q;
            q=p;
            p=current;
        }
        head=q;
        cout<<"逆置成功"<<endl;
    }
};

int main() {
    LinkedList l;
    vector<int> v = {1, 2, 6, 3, 4, 5, 6};
    l.Insert_Linked(v);
    l.printLike();

    l.deleteLink(6);
    l.printLike();

    l.reverse();
    l.printLike();
    

    return 0;
}
