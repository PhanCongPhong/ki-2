#include<stdio.h>
#include<stdlib.h>
#include <math.h>
struct LinkedList{
    int data;
    struct LinkedList *next;
 };
 
typedef struct LinkedList *node; 
 
node CreateNode(int value){
    node temp; 
    temp = (node)malloc(sizeof(struct LinkedList)); 
    temp->next = NULL;
    temp->data = value; 
    return temp;
}
 
node AddTail(node head, int value){
    node temp,p;
    temp = CreateNode(value);
    if(head == NULL){
        head = temp;    
    }
    else{
        p  = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
    return head;
}
 
node AddHead(node head, int value){
    node temp = CreateNode(value); 
    if(head == NULL){
        head = temp; 
    }else{
        temp->next = head; 
        head = temp; 
    }
    return head;
}
node AddAt(node head, int value, int position){
    if(position == 0 || head == NULL){
        head = AddHead(head, value); 
    }else{
        
        int k = 1;
        node p = head;
        while(p != NULL && k != position){
            p = p->next;
            ++k;
        }
 
        if(k != position){
            head = AddTail(head, value);
        }else{
            node temp = CreateNode(value);
            temp->next = p->next;
            p->next = temp;
        }
    }
    return head;
}
void update_list(node head){
    int count=0;
    for(node p = head; p != NULL; p = p->next){
        if (abs(p->data)%2==1)
        {   
            head=AddAt(head,0,count+1);p=p->next;count++;
        }
        count++;
    }
    
}
int main()
{   node head=NULL;
    int n,value;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d",&value);
        head=AddHead(head,value);

    }
    update_list(head);
    for(node p = head; p != NULL; p = p->next){
        printf("%d\n", p->data);
    }
    return 0;
}