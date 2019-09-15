#include<stdio.h>
#include<stdlib.h>
 
struct LinkedList{
    int data;
    struct LinkedList *next;
 };
 
typedef struct LinkedList *node; 
 
node CreateNode(int value){
    node temp; // declare a node
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
node DelHead(node head){
    if(head == NULL){
        printf("\nerror");
    }else{
        head = head->next;
    }
    return head;
}
 
node DelTail(node head){
    node p = head;
    while(p->next->next != NULL){
        p = p->next;
    }
    p->next = p->next->next; 
    return head;
}
 
node DelAt(node head, int position){
    if(position == 0 || head == NULL){
        head = DelHead(head); 
    }else{

        int k = 1;
        node p = head;
        while(p->next->next != NULL && k != position){
            p = p->next;
            ++k;
        }
 
        if(k != position){
            head = DelTail(head);
        }else{
            p->next = p->next->next;
        }
    }
    return head;
}
int main()
{   node head=NULL;
    int n,value,count=0;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d",&value);
        head=AddTail(head,value);

    }
    for(node p = head; p != NULL; p = p->next){
        if ((p->data)%2==0)
        {   
            head=DelAt(head,count);count--;
        }
        count++;
    }
    for(node p = head; p != NULL; p = p->next){
        printf("%d ", p->data);
    }
    return 0;
}