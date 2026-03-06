//Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node{
    int data;
    struct Node* next;
};

void push(struct Node** top,int val){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=val;
    temp->next=*top;
    *top=temp;
}

int pop(struct Node** top){
    struct Node* temp=*top;
    int val=temp->data;
    *top=temp->next;
    free(temp);
    return val;
}

int main(){
    char expr[200];
    struct Node* top=NULL;

    fgets(expr,sizeof(expr),stdin);

    char* token=strtok(expr," ");

    while(token!=NULL){
        if(isdigit(token[0]) || (token[0]=='-' && isdigit(token[1]))){
            push(&top,atoi(token));
        }
        else{
            int b=pop(&top);
            int a=pop(&top);
            int res;

            if(token[0]=='+') res=a+b;
            else if(token[0]=='-') res=a-b;
            else if(token[0]=='*') res=a*b;
            else res=a/b;

            push(&top,res);
        }

        token=strtok(NULL," ");
    }

    printf("%d",pop(&top));
    return 0;
}