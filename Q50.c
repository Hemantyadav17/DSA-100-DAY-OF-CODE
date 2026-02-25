//Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

//There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer
// Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). 
//It is -1 if there is no cycle. Note that pos is not passed as a parameter.

//Do not modify the linked list.


#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode *detectCycle(struct ListNode *head)
{
    struct ListNode *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }

    return NULL;
}

int main()
{
    int n, pos;
    scanf("%d", &n);

    struct ListNode *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++)
    {
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        scanf("%d", &node->val);
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

    scanf("%d", &pos);

    if (pos >= 0 && head != NULL)
    {
        struct ListNode* temp = head;
        for (int i = 0; i < pos; i++)
            temp = temp->next;
        tail->next = temp;
    }

    struct ListNode* cycleNode = detectCycle(head);

    if (cycleNode == NULL)
        printf("no cycle");
    else
        printf("tail connects to node index %d", pos);

    return 0;
}