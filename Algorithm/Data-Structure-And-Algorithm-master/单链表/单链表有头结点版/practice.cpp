#include <iostream>

// ����ڵ�ṹ��
struct Node {
    int data;
    Node* next;
};

// ����������
class LinkedList {
public:
    // ���캯������ʼ��ͷ�ڵ�
    LinkedList() {
        head = new Node;  // ����ͷ�ڵ�
        head->next = nullptr;
    }

    // �����������ͷ�������ڴ�
    ~LinkedList() {
        clear();
        delete head;
    }

    // �����½ڵ㵽����ĩβ
    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    // ��ӡ����
    void print() const {
        Node* current = head->next;  // ����ͷ�ڵ�
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // �������
    void clear() {
        Node* current = head->next;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head->next = nullptr;
    }
     // ɾ��ָ��ֵ�Ľڵ�
    void deleteNode(int value) {
        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->data == value) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
        std::cout << "Value " << value << " not found in the list." << std::endl;
    }

private:
    Node* head;  // ͷ�ڵ�
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);

    std::cout << "��������: ";
    list.print();

    list.clear();
    std::cout << "���������" << std::endl;

    return 0;
}
