//Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* newNode(int c, int e) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->coeff = c;
    temp->exp = e;
    temp->next = NULL;
    return temp;
}

struct Node* insertEnd(struct Node* head, int c, int e) {
    struct Node* temp = newNode(c, e);
    if (!head) return temp;

    struct Node* p = head;
    while (p->next) p = p->next;
    p->next = temp;
    return head;
}

void printPoly(struct Node* head) {
    struct Node* p = head;
    while (p) {
        if (p->exp == 0)
            printf("%d", p->coeff);
        else if (p->exp == 1)
            printf("%dx", p->coeff);
        else
            printf("%dx^%d", p->coeff, p->exp);

        if (p->next) printf(" + ");
        p = p->next;
    }
}

int main() {
    int n, c, e;
    struct Node* head = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        head = insertEnd(head, c, e);
    }

    printPoly(head);
    return 0;
}