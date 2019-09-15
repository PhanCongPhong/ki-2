#include <stdio.h>
#include <stdlib.h>
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
int main()
{
	node head=NULL;
	int n,value;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&value);
		head=AddTail(head,value);

	}
	for(node p = head; p != NULL; p = p->next){
		if((p->data)%2==0)
        {printf("%d ", p->data);}
    }
	return 0;
}