// Implement a first in first out (FIFO) queue using only two stacks. 
//The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).


#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int s1[MAX], s2[MAX];
int top1 = -1, top2 = -1;

void push(int x){
    s1[++top1] = x;
}

void transfer(){
    if(top2 == -1){
        while(top1 != -1){
            s2[++top2] = s1[top1--];
        }
    }
}

int pop(){
    transfer();
    return s2[top2--];
}

int peek(){
    transfer();
    return s2[top2];
}

bool empty(){
    return top1 == -1 && top2 == -1;
}

int main(){
    push(1);
    push(2);

    printf("%d\n", peek());
    printf("%d\n", pop());

    if(empty())
        printf("true");
    else
        printf("false");

    return 0;
}