//Design your implementation of the circular double-ended queue (deque).

//Implement the MyCircularDeque class:

//MyCircularDeque(int k) Initializes the deque with a maximum size of k.
//boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
//boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
//boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
//boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
//int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
//int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
//boolean isEmpty() Returns true if the deque is empty, or false otherwise.
//boolean isFull() Returns true if the deque is full, or false otherwise.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1, size = 0, capacity;

bool isEmpty(){
    return size == 0;
}

bool isFull(){
    return size == capacity;
}

bool insertFront(int x){
    if(isFull()) return false;

    if(isEmpty()){
        front = rear = 0;
    }
    else{
        front = (front - 1 + capacity) % capacity;
    }

    deque[front] = x;
    size++;
    return true;
}

bool insertLast(int x){
    if(isFull()) return false;

    if(isEmpty()){
        front = rear = 0;
    }
    else{
        rear = (rear + 1) % capacity;
    }

    deque[rear] = x;
    size++;
    return true;
}

bool deleteFront(){
    if(isEmpty()) return false;

    if(front == rear){
        front = rear = -1;
    }
    else{
        front = (front + 1) % capacity;
    }

    size--;
    return true;
}

bool deleteLast(){
    if(isEmpty()) return false;

    if(front == rear){
        front = rear = -1;
    }
    else{
        rear = (rear - 1 + capacity) % capacity;
    }

    size--;
    return true;
}

int getFront(){
    if(isEmpty()) return -1;
    return deque[front];
}

int getRear(){
    if(isEmpty()) return -1;
    return deque[rear];
}

int main(){
    capacity = 3;

    insertLast(1);
    insertLast(2);
    insertFront(3);

    printf("%d\n", getRear());
    printf("%d\n", isFull());

    deleteLast();
    insertFront(4);

    printf("%d\n", getFront());

    return 0;
}