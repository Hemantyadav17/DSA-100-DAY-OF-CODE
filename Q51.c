//Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};

int main()
{
    int n;
    scanf("%d", &n);

    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++)
    {
        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &node->data);
        node->prev = tail;
        node->next = NULL;

        if (head == NULL)
            head = node;
        else
            tail->next = node;

        tail = node;
    }

    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
