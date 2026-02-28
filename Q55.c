//Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if (head == NULL) {
        temp->next = temp;
        return temp;
    }

    struct Node* p = head;
    while (p->next != head)
        p = p->next;

    p->next = temp;
    temp->next = head;
    return head;
}

void traverse(struct Node* head) {
    if (!head) return;

    struct Node* p = head;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
}

int main() {
    int n, x;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    traverse(head);
    return 0;
}