//Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

#include <stdio.h>

#define MAX 1000

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) return;
    stack[++top] = x;
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d\n", stack[top--]);
}

void display() {
    if (top == -1) {
        printf("\n");
        return;
    }
    for (int i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i > 0) printf(" ");
    }
    printf("\n");
}

int main() {
    int n, type, val;
    scanf("%d", &n);

    while (n--) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d", &val);
            push(val);
        } else if (type == 2) {
            pop();
        } else if (type == 3) {
            display();
        }
    }
    return 0;
}