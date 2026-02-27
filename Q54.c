//Given the head of a singly linked list, the task is to remove a cycle if present. 
//A cycle exists when a node's next pointer points back to a previous node, forming a loop.
//Internally, a variable pos denotes the index of the node where the cycle starts, but it is not passed as a parameter. The terminal will print true if a cycle is removed otherwise, it will print false.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void createCycle(struct Node* head, int pos) {
    if (pos == 0) return;

    struct Node *cycleNode = NULL, *temp = head;
    int index = 1;

    while (temp->next) {
        if (index == pos)
            cycleNode = temp;
        temp = temp->next;
        index++;
    }

    if (cycleNode)
        temp->next = cycleNode;
}

bool removeCycle(struct Node* head) {
    if (!head) return false;

    struct Node *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            slow = head;

            if (slow == fast) {
                while (fast->next != slow)
                    fast = fast->next;
                fast->next = NULL;
                return true;
            }

            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }

            fast->next = NULL;
            return true;
        }
    }

    return true;
}

int main() {
    int n, pos, x;
    struct Node *head = NULL, *tail = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        struct Node* temp = newNode(x);
        if (!head)
            head = tail = temp;
        else {
            tail->next = temp;
            tail = temp;
        }
    }

    scanf("%d", &pos);

    createCycle(head, pos);

    if (removeCycle(head))
        printf("true");
    else
        printf("false");

    return 0;
}