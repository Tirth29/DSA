#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *next;
}*first=NULL;

void insertlast(int x)
{
    struct node *t,*last;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;
    if(first==NULL)
    {
        first=last=t;
    }
    else
    {
       
         last->next=t;
        last=t;
    }
}

void display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main()
{
    insertlast(1);
    display(first);
    printf("-------------------------------->");
    insertlast(2);
    insertlast(3);
    insertlast(4);
    display(first);
    insertlast(5);
    insertlast(6);
    printf("-------------------------------->");
    display(first);
}