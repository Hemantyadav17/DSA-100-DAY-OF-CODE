//Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
//A node in a singly linked list should have two attributes: val and next.
// val is the value of the current node, and next is a pointer/reference to the next node.
//If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. 
//Assume all nodes in the linked list are 0-indexed.


#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node* next;
};

typedef struct {
    struct Node* head;
    int size;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return -1;

    struct Node* temp = obj->head;
    for (int i = 0; i < index; i++)
        temp = temp->next;

    return temp->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->next = obj->head;
    obj->head = node;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->next = NULL;

    if (obj->head == NULL)
        obj->head = node;
    else {
        struct Node* temp = obj->head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = node;
    }

    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size)
        return;

    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;

    struct Node* temp = obj->head;
    for (int i = 0; i < index - 1; i++)
        temp = temp->next;

    node->next = temp->next;
    temp->next = node;
    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return;

    struct Node* temp = obj->head;

    if (index == 0) {
        obj->head = temp->next;
        free(temp);
    } else {
        for (int i = 0; i < index - 1; i++)
            temp = temp->next;

        struct Node* del = temp->next;
        temp->next = del->next;
        free(del);
    }

    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    struct Node* temp = obj->head;
    while (temp != NULL) {
        struct Node* next = temp->next;
        free(temp);
        temp = next;
    }
    free(obj);
}

int main() {
    MyLinkedList* list = myLinkedListCreate();

    myLinkedListAddAtHead(list, 1);
    myLinkedListAddAtTail(list, 3);
    myLinkedListAddAtIndex(list, 1, 2);

    printf("%d\n", myLinkedListGet(list, 1));

    myLinkedListDeleteAtIndex(list, 1);

    printf("%d\n", myLinkedListGet(list, 1));

    myLinkedListFree(list);
    return 0;
}