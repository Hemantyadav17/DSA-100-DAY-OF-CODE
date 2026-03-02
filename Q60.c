//You are given two non-empty linked lists representing two non-negative integers. 
//The most significant digit comes first and each of their nodes contains a single digit. 
//Add the two numbers and return the sum as a linked list.

#include <stdio.h>
#include <stdlib.h>

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

struct ListNode* reverse(struct ListNode* head) {
    struct ListNode *prev = NULL, *curr = head, *nextNode;
    while (curr) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    l1 = reverse(l1);
    l2 = reverse(l2);

    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode* tail = &dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;

        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;

        struct ListNode* node = newNode(sum % 10);
        tail->next = node;
        tail = node;
    }

    return reverse(dummy.next);
}

void printList(struct ListNode* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main() {
    int n1, n2, x;
    struct ListNode *l1 = NULL, *l2 = NULL, *tail = NULL;

    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &x);
        struct ListNode* temp = newNode(x);
        if (!l1)
            l1 = tail = temp;
        else {
            tail->next = temp;
            tail = temp;
        }
    }

    tail = NULL;

    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &x);
        struct ListNode* temp = newNode(x);
        if (!l2)
            l2 = tail = temp;
        else {
            tail->next = temp;
            tail = temp;
        }
    }

    struct ListNode* result = addTwoNumbers(l1, l2);
    printList(result);
    return 0;
}