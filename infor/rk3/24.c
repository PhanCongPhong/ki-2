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
node AddHead(node head, int value){
    node temp = CreateNode(value); // Khởi tạo node temp với data = value
    if(head == NULL){
        head = temp; // //Nếu linked list đang trống thì Node temp là head luôn
    }else{
        temp->next = head; // Trỏ next của temp = head hiện tại
        head = temp; // Đổi head hiện tại = temp(Vì temp bây giờ là head mới mà)
    }
    return head;
}
// node DelTail(node head){
//     node p = head;
//     while(p->next->next != NULL){
//         p = p->next;
//     }
//     p->next = p->next->next; 
//     return head;
// }
int main()
{
	node head=NULL;
	int n,value,s;
	scanf("%d",&n);
    
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&value);
		head=AddHead(head,value);

	}
   // for (int i = 0; i < s; ++i)
   // {
   //     head=DelTail(head);
   // }
        for(node p = head; p != NULL; p = p->next){
        printf("%d ", p->data);
    }
	return 0;
}