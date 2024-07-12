#include<iostream>
#include<string>
#include<vector>
using namespace std;

template<typename T>
class LinkedList{
    private:
        struct Node{
            T data;
            Node* next;
            Node(T val):data(val),next(nullptr){}
        };
        Node* head;

    public:
        LinkedList() : head(nullptr) {}

        void insert(const vector<T> &v){
            if(v.empty()) return;
            head = new Node(v[0]);
            Node* current = head;
            for(size_t i = 1; i < v.size(); i++){
                current->next = new Node(v[i]);
                current = current->next;
            }
            cout << "插入成功" << endl;
        }

        void printlist() const {
            Node* current = head;
            while(current != nullptr){
                cout << current->data << "->";
                current = current->next;
            }
            cout << "nullptr" << endl;
        }

        void invertList(){
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

int main(){
    LinkedList<string> ls;
    vector<string> vec = {"ss", "tt", "kk"};
    ls.insert(vec);
    ls.printlist();
    ls.invertList();
    ls.printlist();

    return 0;
}
