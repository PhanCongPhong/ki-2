#include<stdio.h>
#include<stdlib.h>
typedef struct  point
{
    int x;int y;
}Point;
typedef struct node
{
   int value;
   struct node *next;
}Node;
void push(Node **head, int value){
    Node *tmp =malloc(sizeof(Node));
    tmp->value =value;
    tmp->next =(*head);
    (*head)=tmp;
}
int pop(Node **head){
   Node *prev=NULL;
   int val;
   if (*head == NULL)
   {
      exit(-1);
   }
   prev =(*head);
   val = prev->value;
   (*head)=(*head)->next;
   free(prev);
   return val;
}

int main(){
    Node *head=NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);
    printf("pop=%d  ",pop(&head));
    printf("pop=%d",pop(&head));
    printf("pop=%d",pop(&head));
    printf("pop=%d",pop(&head));
    return 0;
}
