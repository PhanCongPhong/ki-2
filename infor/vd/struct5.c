#include <stdio.h>
#include <stdlib.h>
typedef struct  node 
{
	int value;
	struct  node *next;
	
}list_node_t;
typedef struct list
{
	size_t size;
	list_node_t *head;
} list_t;
list_t *init_list(void);
void push_list_node(list_t*,int);
int pop_list_node(list_t*);
void print_list(list_t*);
void destruct_list(list_t*);
void concat_lists(list_t*, list_t*);
int main()
{
    list_t *list_1=init_list();
    list_t *list_2=init_list();
    push_list_node(list_1,3);	
    push_list_node(list_1,4);
    push_list_node(list_1,5);
    push_list_node(list_1,6);
    push_list_node(list_1,7);
     
     // printf("delete val %d\n", pop_list_node(list_1));
    push_list_node(list_2,9);
     push_list_node(list_2,10);
     push_list_node(list_2,7);
     
     concat_lists(list_1,list_2);
    print_list(list_1);
    printf("\n");
    print_list(list_2);
     destruct_list(list_1);
     destruct_list(list_1);
	return 0;
}
list_t *init_list(void){
	list_t *list=(list_t *)malloc(sizeof(list_t));
	list->size=0;
	list->head=NULL;
	return list;
}
void push_list_node(list_t *list,int value){
list_node_t *node=(list_node_t*)malloc(sizeof(list_node_t));
node->value=value;
node->next=list->head;
list->head=node;
list->size++;
}
int pop_list_node(list_t *list){
list_node_t *tmp=list->head;
if (tmp==NULL)
{
	printf("ERRROR\n");
	exit(-1);

}
int val=list->head->value;
	list->head=list->head->next;
	list->size --;
	free(tmp);
return val;
}
void destruct_list(list_t *list){
	while(list->size)
	{
		pop_list_node(list);
	}
	free(list);
}
void concat_lists(list_t *list_1,list_t *list_2){
	list_node_t *node =list_1->head;
	while(node->next !=NULL)
	{
		node=node->next;
	}
	node->next=list_2->head;
}
void print_list(list_t *list){
	list_node_t *node= list->head;
	while (node!=NULL){
		printf("%d ",node->value );
		node=node->next;
	}
}