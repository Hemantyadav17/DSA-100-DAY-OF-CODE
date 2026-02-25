//Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

int countOccurrences(struct Node* head, int key)
{
    int count = 0;
    struct Node* temp = head;

    while (temp != NULL)
    {
        if (temp->data == key)
            count++;
        temp = temp->next;
    }

    return count;
}

int main()
{
    int n;
    scanf("%d", &n);

    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++)
    {
        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &node->data);
        node->next = NULL;

        if (head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
    }

    int key;
    scanf("%d", &key);

    int result = countOccurrences(head, key);
    printf("%d", result);

    return 0;
}