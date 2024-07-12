#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct Node {
    char* data;
    struct Node* next;
} Node;

// 创建新节点
Node* createNode(char* val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// 插入节点
void insert(Node** head, char* val) {
    Node* newNode = createNode(val);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    printf("插入成功\n");
}

// 打印链表
void printList(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%s->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 逆置链表
void invertList(Node** head) {
    Node* q = NULL;
    Node* p = *head;
    while (p!= NULL) {
        Node* current = p->next;
        p->next = q;
        q = p;
        p = current;
    }
    *head = q;
    printf("逆置成功\n");
}

int main() {
    Node* head = NULL;
    char* vec[] = {"ss", "tt", "kk"};
    int vecSize = sizeof(vec) / sizeof(vec[0]);

    for (int i = 0; i < vecSize; i++) {
        insert(&head, vec[i]);
    }

    printList(head);
    invertList(&head);
    printList(head);

    // 释放链表内存
    Node* temp;
    while (head!= NULL) {
        temp = head;
        head = head->next;
        free(temp->data);
        free(temp);
    }

    return 0;
}