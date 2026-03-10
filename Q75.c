//Problem: Deque (Double-Ended Queue)

//A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear.
// It provides more flexibility than a standard queue or stack.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000

int dq[MAX];
int front = -1, rear = -1;

bool empty(){
    return front == -1;
}

int size(){
    if(front == -1) return 0;
    return rear - front + 1;
}

void push_front(int x){
    if(front == -1){
        front = rear = 0;
        dq[front] = x;
    }
    else if(front > 0){
        dq[--front] = x;
    }
}

void push_back(int x){
    if(front == -1){
        front = rear = 0;
        dq[rear] = x;
    }
    else{
        dq[++rear] = x;
    }
}

void pop_front(){
    if(front == -1) return;
    if(front == rear)
        front = rear = -1;
    else
        front++;
}

void pop_back(){
    if(front == -1) return;
    if(front == rear)
        front = rear = -1;
    else
        rear--;
}

int get_front(){
    if(front == -1) return -1;
    return dq[front];
}

int get_back(){
    if(front == -1) return -1;
    return dq[rear];
}

void display(){
    if(front == -1){
        printf("Deque is empty\n");
        return;
    }
    for(int i = front; i <= rear; i++){
        printf("%d ", dq[i]);
    }
    printf("\n");
}

int main(){
    int n, x;
    char op[20];

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%s", op);

        if(strcmp(op,"push_front")==0){
            scanf("%d",&x);
            push_front(x);
        }
        else if(strcmp(op,"push_back")==0){
            scanf("%d",&x);
            push_back(x);
        }
        else if(strcmp(op,"pop_front")==0){
            pop_front();
        }
        else if(strcmp(op,"pop_back")==0){
            pop_back();
        }
        else if(strcmp(op,"front")==0){
            printf("%d\n", get_front());
        }
        else if(strcmp(op,"back")==0){
            printf("%d\n", get_back());
        }
        else if(strcmp(op,"empty")==0){
            printf("%s\n", empty() ? "true" : "false");
        }
        else if(strcmp(op,"size")==0){
            printf("%d\n", size());
        }
    }

    display();
    return 0;
}