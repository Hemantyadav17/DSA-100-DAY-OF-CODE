//Problem Statement:
//Implement a Priority Queue using an array. An element with smaller value has higher priority.

#include <stdio.h>
#include <string.h>

#define MAX 1000

int pq[MAX];
int size = 0;

void insert(int x){
    pq[size++] = x;
}

int findMinIndex(){
    if(size == 0) return -1;
    int minIndex = 0;
    for(int i = 1; i < size; i++){
        if(pq[i] < pq[minIndex])
            minIndex = i;
    }
    return minIndex;
}

void deleteMin(){
    if(size == 0){
        printf("-1\n");
        return;
    }

    int idx = findMinIndex();
    printf("%d\n", pq[idx]);

    for(int i = idx; i < size - 1; i++)
        pq[i] = pq[i + 1];

    size--;
}

void peek(){
    if(size == 0){
        printf("-1\n");
        return;
    }

    int idx = findMinIndex();
    printf("%d\n", pq[idx]);
}

int main(){
    int n, x;
    char op[20];

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%s", op);

        if(strcmp(op, "insert") == 0){
            scanf("%d", &x);
            insert(x);
        }
        else if(strcmp(op, "delete") == 0){
            deleteMin();
        }
        else if(strcmp(op, "peek") == 0){
            peek();
        }
    }

    return 0;
}