#include <stdio.h>
#include <stdlib.h>
struct LinkedList
{
    int data;
    struct LinkedList *next;
};
typedef struct LinkedList *node;

node CreateNode(int value)
{
    node temp;
    temp = (node)malloc(sizeof(struct LinkedList));
    temp->next = NULL;
    temp->data = value;
    return temp;
}
node AddTail(node head, int value)
{
    node temp, p;
    temp = CreateNode(value);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
    return head;
}
node DelHead(node head)
{
    if (head == NULL)
    {
        printf("\nerror");
    }
    else
    {
        head = head->next;
    }
    return head;
}

node DelTail(node head)
{
    node p = head;
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    p->next = p->next->next;
    return head;
}

node DelAt(node head, int position)
{
    if (position == 0 || head == NULL)
    {
        head = DelHead(head);
    }
    else
    {

        int k = 1;
        node p = head;
        while (p->next->next != NULL && k != position)
        {
            p = p->next;
            ++k;
        }

        if (k != position)
        {
            head = DelTail(head);
        }
        else
        {
            p->next = p->next->next;
        }
    }
    return head;
}

int main()
{
    node head1 = NULL;
    node head2 = NULL;
    node head3 = NULL;
    int n1, n2, value, i = 0;
    scanf("%d", &n1);
    for (int i = 0; i < n1; ++i)
    {
        scanf("%d", &value);
        head1 = AddTail(head1, value);
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; ++i)
    {
        scanf("%d", &value);
        head2 = AddTail(head2, value);
    }
    for (node p = head1; p != NULL; p = p->next)
    {
        for (node q = head2; q != NULL; q = q->next)
        {
            if (p->data == q->data)
            {
                head3 = AddTail(head3, p->data);
            }
        }
    }
    for (node p = head3; p != NULL; p = p->next)
    {
        for (node q = p->next; q != NULL; q = q->next)
        {
            if (p->data == q->data)
            {
                head3 = DelAt(head3, i);
                i--;
            }
        }
        i++;
    }
    for (node q = head3; q != NULL; q = q->next)
    {
        printf("%d ", q->data);
    }
    return 0;
}