//Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* deleteFirst(struct Node* head, int key)
{
    if (head == NULL)
        return head;

    if (head->data == key)
    {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* curr = head;

    while (curr->next != NULL)
    {
        if (curr->next->data == key)
        {
            struct Node* temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
            break;
        }
        curr = curr->next;
    }

    return head;
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

    head = deleteFirst(head, key);

    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
