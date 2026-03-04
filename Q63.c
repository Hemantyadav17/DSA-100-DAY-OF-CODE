//Problem: Implement push and pop operations on a stack and verify stack operations.

#include <stdio.h>

#define MAX 1000

int stack[MAX];
int top = -1;

void push(int x) {
    if (top < MAX - 1)
        stack[++top] = x;
}

void pop() {
    if (top >= 0)
        top--;
}

void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i > 0) printf(" ");
    }
}

int main() {
    int n, m, x;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        push(x);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++)
        pop();

    display();
    return 0;
}