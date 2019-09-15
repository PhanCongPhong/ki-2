#include <stdio.h>
#include <stdlib.h>

struct Node{
   Node *next;
   int data;
};

struct List{
   Node *head;
   Node *tail;
};

void Init(List &l){
   l.head = NULL;
   l.tail = NULL;
}

Node *createNode(int x){
   Node *p = (Node*)malloc(sizeof(Node));
   p->data = x;
   p->next = NULL;
   return p;
}
void addTail(List &l, Node *p){
   if(!l.head) l.head = l.tail = p;
   else{
      l.tail->next = p;
      l.tail = p;
   }
}

void reverse(List &l){
   Node *parent = l.head ;
   Node *current = l.head->next;
   l.head = current->next;
   parent->next = NULL;
   current->next = parent;
   while(l.head->next){
      parent = current;
      current = l.head;
      l.head = l.head->next;
      current->next = parent;
   }
   l.head->next = current;
   
}

void display(List l){
   while(l.head){
     printf("%d ",l.head->data );
      l.head = l.head->next;
   }
}

void insert(List &l){
   int n,value;
  scanf("%d",&n);
   for(int i = 1; i<= n; i++){
      scanf("%d",&value);
      Node *p = createNode(value);
      addTail(l,p);
   }
}

int main(){
   List l;
   Init(l);
   insert(l);
   reverse(l);
   display(l);
   return 0;
}
