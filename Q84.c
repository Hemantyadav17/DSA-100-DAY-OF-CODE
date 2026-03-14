//The median is the middle value in an ordered integer list. 
//If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.



#include <stdio.h>

#define MAX 100000

int small[MAX], large[MAX];
int sizeSmall=0, sizeLarge=0;

void swap(int *a,int *b){
    int t=*a; *a=*b; *b=t;
}

void maxHeapUp(int i){
    while(i>0){
        int p=(i-1)/2;
        if(small[p]>=small[i]) break;
        swap(&small[p],&small[i]);
        i=p;
    }
}

void maxHeapDown(int n,int i){
    while(1){
        int l=2*i+1,r=2*i+2,b=i;
        if(l<n && small[l]>small[b]) b=l;
        if(r<n && small[r]>small[b]) b=r;
        if(b==i) break;
        swap(&small[i],&small[b]);
        i=b;
    }
}

void minHeapUp(int i){
    while(i>0){
        int p=(i-1)/2;
        if(large[p]<=large[i]) break;
        swap(&large[p],&large[i]);
        i=p;
    }
}

void minHeapDown(int n,int i){
    while(1){
        int l=2*i+1,r=2*i+2,b=i;
        if(l<n && large[l]<large[b]) b=l;
        if(r<n && large[r]<large[b]) b=r;
        if(b==i) break;
        swap(&large[i],&large[b]);
        i=b;
    }
}

void addNum(int num){

    if(sizeSmall==0 || num<=small[0]){
        small[sizeSmall]=num;
        maxHeapUp(sizeSmall);
        sizeSmall++;
    }else{
        large[sizeLarge]=num;
        minHeapUp(sizeLarge);
        sizeLarge++;
    }

    if(sizeSmall > sizeLarge+1){
        int val=small[0];
        small[0]=small[sizeSmall-1];
        sizeSmall--;
        maxHeapDown(sizeSmall,0);

        large[sizeLarge]=val;
        minHeapUp(sizeLarge);
        sizeLarge++;
    }
    else if(sizeLarge > sizeSmall){
        int val=large[0];
        large[0]=large[sizeLarge-1];
        sizeLarge--;
        minHeapDown(sizeLarge,0);

        small[sizeSmall]=val;
        maxHeapUp(sizeSmall);
        sizeSmall++;
    }
}

double findMedian(){
    if(sizeSmall>sizeLarge) return small[0];
    return (small[0]+large[0])/2.0;
}

int main(){

    addNum(1);
    addNum(2);
    printf("%.1f\n",findMedian());
    addNum(3);
    printf("%.1f\n",findMedian());

    return 0;
}