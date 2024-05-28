#include <iostream>

// 定义节点结构体
struct Node {
    int data;
    Node* next;
};

// 创建链表类
class LinkedList {
public:
    // 构造函数，初始化头节点
    LinkedList() {
        head = new Node;  // 创建头节点
        head->next = nullptr;
    }

    // 析构函数，释放链表的内存
    ~LinkedList() {
        clear();
        delete head;
    }

    // 插入新节点到链表末尾
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

    // 打印链表
    void print() const {
        Node* current = head->next;  // 跳过头节点
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // 清空链表
    void clear() {
        Node* current = head->next;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head->next = nullptr;
    }
     // 删除指定值的节点
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
    Node* head;  // 头节点
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);

    std::cout << "链表内容: ";
    list.print();

    list.clear();
    std::cout << "链表已清空" << std::endl;

    return 0;
}
