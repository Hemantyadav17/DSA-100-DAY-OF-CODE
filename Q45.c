//Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* mergeLists(struct Node* l1, struct Node* l2)
{
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL)
    {
        if (l1->data <= l2->data)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != NULL)
        tail->next = l1;
    else
        tail->next = l2;

    return dummy.next;
}

int main()
{
    int n, m;
    scanf("%d", &n);

    struct Node *head1 = NULL, *tail1 = NULL;
    for (int i = 0; i < n; i++)
    {
        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &node->data);
        node->next = NULL;

        if (head1 == NULL)
        {
            head1 = node;
            tail1 = node;
        }
        else
        {
            tail1->next = node;
            tail1 = node;
        }
    }

    scanf("%d", &m);

    struct Node *head2 = NULL, *tail2 = NULL;
    for (int i = 0; i < m; i++)
    {
        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &node->data);
        node->next = NULL;

        if (head2 == NULL)
        {
            head2 = node;
            tail2 = node;
        }
        else
        {
            tail2->next = node;
            tail2 = node;
        }
    }

    struct Node* merged = mergeLists(head1, head2);

    while (merged != NULL)
    {
        printf("%d ", merged->data);
        merged = merged->next;
    }

    return 0;
}