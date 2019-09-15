#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 100
int top=-1;
double stack[STACK_SIZE];
void push(double n){
    if (top+1<STACK_SIZE) {
        stack[++top]=n;
    }
    else
    {
        printf("eror:stack is full\n");
    }   
}
double pop(){
    if (top!=-1) {
        return stack[top--];
    }
    else
    {
        printf("stack is empty\n");
       return 0.0;
    }
    
    
}