#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�ṹ��
typedef struct Node {
    char* data;
    struct Node* next;
} Node;

// �����½ڵ�
Node* createNode(char* val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// ����ڵ�
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
    printf("����ɹ�\n");
}

// ��ӡ����
void printList(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%s->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// ��������
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
    printf("���óɹ�\n");
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

    // �ͷ������ڴ�
    Node* temp;
    while (head!= NULL) {
        temp = head;
        head = head->next;
        free(temp->data);
        free(temp);
    }

    return 0;
}