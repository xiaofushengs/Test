#include <iostream>
using namespace std;

// ��������ڵ�ģ����
template<typename T>
struct Node {
    T data;
    Node* next;
    Node(T value) : data(value), next(nullptr) {}
};

// ������ʽ����ģ����
template<typename T>
class LinkedQueue {
private:
    Node<T>* front;  // ָ�����ͷ����ָ��
    Node<T>* rear;   // ָ�����β����ָ��
    int size;        // �����е�Ԫ�ظ���

public:
    LinkedQueue() : front(nullptr), rear(nullptr), size(0) {}

    ~LinkedQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // �������Ƿ�Ϊ��
    bool isEmpty() const {
        return size == 0;
    }

    // ���ض����е�Ԫ�ظ���
    int getSize() const {
        return size;
    }

    // ��ȡ����ͷ����Ԫ��
    T getFront() const {
        if (isEmpty()) {
            cerr << "����Ϊ�գ��޷���ȡԪ��!" << endl;
            exit(1);
        }
        return front->data;
    }

    // ��Ӳ���
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

    // ���Ӳ���
    void dequeue() {
        if (isEmpty()) {
            cerr << "����Ϊ�գ��޷�����!" << endl;
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

    cout << "���д�С: " << queue.getSize() << endl;
    cout << "����ͷ��Ԫ��: " << queue.getFront() << endl;

    queue.dequeue();
    cout << "���Ӻ����ͷ��Ԫ��: " << queue.getFront() << endl;
    cout << "���д�С: " << queue.getSize() << endl;

    return 0;
}
