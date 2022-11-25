#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
}*head = NULL;

void create(int a[],int n)
{
    struct node *t,*last;
    head = (struct node *)malloc(sizeof(struct node));
    head->data =a[0];
    head->next = head->prev = NULL;
    last=head;

    for(int i= 1; i < n; i++)
    {
        t= (struct node *)malloc(sizeof(struct node));
        t->data =a[i];
        t->next = head->prev=NULL;
        t->prev =last;
        last->next = t;
        last=t;

    }

}

void display(struct node *p)
{
    while(p)
    {
        printf("%d  ", p->data);
        p=p->next;
    }
    printf("\n");
}

int length(struct node *p)
{
    int len = 0;
    while(p)
    {
        len++;
        p=p->next;
    }
    return len;
}

void insert(struct node *p,int index,int x)
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    t->next=t->prev=NULL;
    if(index<0 && index>length(p))
        return;
    if(index==0)
    {
        t->prev=NULL;
        t->next=head;
        head->prev=t;
        head=t;
    }
    else
    {
        for(int i=0;i<index-2;i++)
            p=p->next;

        t->next=p->next;
        p->next=t;
        t->prev=p;
        t->next->prev=t;
    
    }

    
}

int delete(struct node *p,int index)
{
    // struct node *t;
    int x;
    if(index<1 && index>length(p)) 
        return;
    if(index==1)
    {
        p=p->next;
        if(head)
            head->prev=NULL;
        x=p->data;
        free(p);
    }
    else
    {
        for(int i=0;i<index-1;i++)
            p=p->next;
        x=p->data;
        p->prev->next=p->next;
        p->next->prev=p->prev;
        free(p);
    }
    printf("\n");
    return x;
}

void reverse(struct node *p)
{
    struct node *temp;
    while(p)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p && p->next==NULL)
            head=p;
    }

}

int main()
{
    int a[] = {1, 2, 3, 4, 5,6};
    create(a,5);
    display(head);
    insert(head,3,7);
    display(head);
    delete(head,2);
    display(head);
    reverse(head);
    display(head);
    return 0;
}