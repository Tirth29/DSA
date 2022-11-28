#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

void sortedinsert(struct node **h, int x)
{
    struct node *t, *q=NULL, *p=*h;
    t=(struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;

    if(*h==NULL)
        *h=t;
    else 
    {
        while(p && p->data < x)
        {
            q=p;
            p=p->next;
        }
        if(p==*h)
        {
            t->next=*h;
            *h=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }
}

struct node *search(struct node *p,int key)
{
    while (p)
    {
        if(key==p->data)
        {
            return p;
        }
        p=p->next;
    }
    return NULL;
}
