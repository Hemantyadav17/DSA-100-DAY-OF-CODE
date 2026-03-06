//Given a string s which represents an expression, evaluate this expression and return its value. 

//The integer division should truncate toward zero.


#include <stdio.h>
#include <ctype.h>
#include <string.h>

int calculate(char* s) {
    long stack[1000];
    int top = -1;
    long num = 0;
    char op = '+';

    for (int i = 0; s[i] != '\0'; i++) {

        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }

        if ((!isdigit(s[i]) && s[i] != ' ') || s[i + 1] == '\0') {

            if (op == '+') stack[++top] = num;
            else if (op == '-') stack[++top] = -num;
            else if (op == '*') stack[top] = stack[top] * num;
            else if (op == '/') stack[top] = stack[top] / num;

            op = s[i];
            num = 0;
        }
    }

    int result = 0;

    while (top >= 0) {
        result += stack[top--];
    }

    return result;
}

int main() {
    char s[1000];

    fgets(s, sizeof(s), stdin);

    printf("%d", calculate(s));

    return 0;
}