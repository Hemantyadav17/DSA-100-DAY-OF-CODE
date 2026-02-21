//Given the head of a singly linked list, return the middle node of the linked list.
//If there are two middle nodes, return the second middle node.

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{
    int n;
    scanf("%d", &n);

    struct ListNode *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++)
    {
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        scanf("%d", &newNode->val);
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    struct ListNode* mid = middleNode(head);

    while (mid != NULL)
    {
        printf("%d ", mid->val);
        mid = mid->next;
    }

    return 0;
}