//Given the head of a linked list and an integer val
// remove all the nodes of the linked list that has Node.val == val, and return the new head.

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* removeElements(struct ListNode* head, int val)
{
    while (head != NULL && head->val == val)
    {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    struct ListNode* curr = head;

    while (curr != NULL && curr->next != NULL)
    {
        if (curr->next->val == val)
        {
            struct ListNode* temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        }
        else
        {
            curr = curr->next;
        }
    }

    return head;
}

int main()
{
    int n;
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

    int val;
    scanf("%d", &val);

    head = removeElements(head, val);

    struct ListNode* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }

    return 0;
}