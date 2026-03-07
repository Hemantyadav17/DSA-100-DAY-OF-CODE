//Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.



#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int queue[MAX];
int front = 0, rear = -1;

void enqueue(int x){
    if(rear < MAX-1)
        queue[++rear] = x;
}

void display(){
    for(int i = front; i <= rear; i++){
        printf("%d", queue[i]);
        if(i < rear) printf(" ");
    }
}

int main(){
    int n,x;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        enqueue(x);
    }

    display();
    return 0;
}