//You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.

//You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.

//Implement the KthLargest class:

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int heap[MAX];
int size=0,k;

void swap(int *a,int *b){
    int t=*a; *a=*b; *b=t;
}

void heapifyUp(int i){
    while(i>0){
        int p=(i-1)/2;
        if(heap[p] <= heap[i]) break;
        swap(&heap[p],&heap[i]);
        i=p;
    }
}

void heapifyDown(int i){
    while(1){
        int l=2*i+1,r=2*i+2,s=i;
        if(l<size && heap[l] < heap[s]) s=l;
        if(r<size && heap[r] < heap[s]) s=r;
        if(s==i) break;
        swap(&heap[i],&heap[s]);
        i=s;
    }
}

void add(int val){
    if(size<k){
        heap[size]=val;
        heapifyUp(size);
        size++;
    }
    else if(val>heap[0]){
        heap[0]=val;
        heapifyDown(0);
    }
}

int main(){
    int n,x;

    scanf("%d %d",&k,&n);

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        add(x);
    }

    int q;
    scanf("%d",&q);

    while(q--){
        scanf("%d",&x);
        add(x);
        printf("%d\n",heap[0]);
    }

    return 0;
}
