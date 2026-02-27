//Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insert(struct Node* head, int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
        return temp;

    struct Node* p = head;
    while (p->next)
        p = p->next;
    p->next = temp;
    return head;
}

int length(struct Node* head) {
    int cnt = 0;
    while (head) {
        cnt++;
        head = head->next;
    }
    return cnt;
}

struct Node* advance(struct Node* head, int d) {
    while (d--)
        head = head->next;
    return head;
}

void findIntersection(struct Node* h1, struct Node* h2) {
    int n1 = length(h1);
    int n2 = length(h2);

    if (n1 > n2)
        h1 = advance(h1, n1 - n2);
    else
        h2 = advance(h2, n2 - n1);

    while (h1 && h2) {
        if (h1->data == h2->data) {
            printf("%d", h1->data);
            return;
        }
        h1 = h1->next;
        h2 = h2->next;
    }

    printf("No Intersection");
}

int main() {
    int n, m, x;
    struct Node *head1 = NULL, *head2 = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head1 = insert(head1, x);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        head2 = insert(head2, x);
    }

    findIntersection(head1, head2);
    return 0;
}