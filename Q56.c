// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* newNode(int val) {
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->val = val;
    temp->next = NULL;
    return temp;
}

bool isPalindrome(struct ListNode* head) {
    if (!head || !head->next) return true;

    struct ListNode *slow = head, *fast = head;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode *prev = NULL, *curr = slow->next, *nextNode;

    while (curr) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    struct ListNode *p1 = head, *p2 = prev;

    while (p2) {
        if (p1->val != p2->val) return false;
        p1 = p1->next;
        p2 = p2->next;
    }

    return true;
}

int main() {
    int n, x;
    struct ListNode *head = NULL, *tail = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        struct ListNode* temp = newNode(x);
        if (!head)
            head = tail = temp;
        else {
            tail->next = temp;
            tail = temp;
        }
    }

    if (isPalindrome(head))
        printf("true");
    else
        printf("false");

    return 0;
}