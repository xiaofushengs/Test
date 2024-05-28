#include <iostream>
using namespace std;

// 定义链表节点模板类
template<typename T>
struct Node {
    T data;
    Node* next;
    Node(T value) : data(value), next(nullptr) {}
};

// 定义链式队列模板类
template<typename T>
class LinkedQueue {
private:
    Node<T>* front;  // 指向队列头部的指针
    Node<T>* rear;   // 指向队列尾部的指针
    int size;        // 队列中的元素个数

public:
    LinkedQueue() : front(nullptr), rear(nullptr), size(0) {}

    ~LinkedQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // 检查队列是否为空
    bool isEmpty() const {
        return size == 0;
    }

    // 返回队列中的元素个数
    int getSize() const {
        return size;
    }

    // 获取队列头部的元素
    T getFront() const {
        if (isEmpty()) {
            cerr << "队列为空，无法获取元素!" << endl;
            exit(1);
        }
        return front->data;
    }

    // 入队操作
    void enqueue(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    // 出队操作
    void dequeue() {
        if (isEmpty()) {
            cerr << "队列为空，无法出队!" << endl;
            exit(1);
        }
        Node<T>* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        size--;
    }
};

int main() {
    LinkedQueue<int> queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "队列大小: " << queue.getSize() << endl;
    cout << "队列头部元素: " << queue.getFront() << endl;

    queue.dequeue();
    cout << "出队后队列头部元素: " << queue.getFront() << endl;
    cout << "队列大小: " << queue.getSize() << endl;

    return 0;
}
