//You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

//Evaluate the expression. Return an integer that represents the value of the expression.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int evalRPN(char tokens[][20], int n) {
    int stack[1000];
    int top = -1;

    for (int i = 0; i < n; i++) {

        if (strcmp(tokens[i], "+") == 0 ||
            strcmp(tokens[i], "-") == 0 ||
            strcmp(tokens[i], "*") == 0 ||
            strcmp(tokens[i], "/") == 0) {

            int b = stack[top--];
            int a = stack[top--];

            if (strcmp(tokens[i], "+") == 0) stack[++top] = a + b;
            else if (strcmp(tokens[i], "-") == 0) stack[++top] = a - b;
            else if (strcmp(tokens[i], "*") == 0) stack[++top] = a * b;
            else stack[++top] = a / b;
        }
        else {
            stack[++top] = atoi(tokens[i]);
        }
    }

    return stack[top];
}

int main() {
    int n;
    scanf("%d", &n);

    char tokens[100][20];

    for (int i = 0; i < n; i++) {
        scanf("%s", tokens[i]);
    }

    int result = evalRPN(tokens, n);

    printf("%d", result);

    return 0;
}