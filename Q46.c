//Given head, the head of a linked list, determine if the linked list has a cycle in it.

//There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

//Return true if there is a cycle in the linked list. Otherwise, return false.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

bool hasCycle(struct ListNode *head)
{
    struct ListNode *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

int main()
{
    int n, pos;
    scanf("%d", &n);

    struct ListNode *head = NULL, *tail = NULL, *cycleNode = NULL;

    for (int i = 0; i < n; i++)
    {
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        scanf("%d", &node->val);
        node->next = NULL;

        if (i == 0)
            head = node;
        else
            tail->next = node;

        tail = node;

        if (i == 0)
            cycleNode = node;
    }

    scanf("%d", &pos);

    if (pos >= 0)
    {
        struct ListNode* temp = head;
        for (int i = 0; i < pos; i++)
            temp = temp->next;
        tail->next = temp;
    }

    if (hasCycle(head))
        printf("true");
    else
        printf("false");

    return 0;
}