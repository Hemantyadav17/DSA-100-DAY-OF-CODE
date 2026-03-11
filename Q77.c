//Problem Statement:
//Implement a Min Heap using an array where the smallest element is always at the root.

#include <stdio.h>
#include <string.h>

#define MAX 1000

int heap[MAX];
int size = 0;

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int i){
    while(i > 0){
        int p = (i - 1) / 2;
        if(heap[p] <= heap[i]) break;
        swap(&heap[p], &heap[i]);
        i = p;
    }
}

void heapifyDown(int i){
    while(1){
        int l = 2*i + 1;
        int r = 2*i + 2;
        int s = i;

        if(l < size && heap[l] < heap[s]) s = l;
        if(r < size && heap[r] < heap[s]) s = r;

        if(s == i) break;

        swap(&heap[i], &heap[s]);
        i = s;
    }
}

void insert(int x){
    heap[size] = x;
    heapifyUp(size);
    size++;
}

void extractMin(){
    if(size == 0){
        printf("-1\n");
        return;
    }

    printf("%d\n", heap[0]);

    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);
}

void peek(){
    if(size == 0){
        printf("-1\n");
        return;
    }

    printf("%d\n", heap[0]);
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
        else if(strcmp(op, "extractMin") == 0){
            extractMin();
        }
        else if(strcmp(op, "peek") == 0){
            peek();
        }
    }

    return 0;
}