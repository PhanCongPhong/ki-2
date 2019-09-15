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
int count_list_nodes(node head){
    int length = 0;
    for(node p = head; p != NULL; p = p->next){
        ++length;
    }
    return length;
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
	int k;
    k=count_list_nodes(head);
    printf("%d",k );
	return 0;
}