#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;
void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create1(int b[],int n)
{
    struct Node *t,*last;
    second =(struct Node *)malloc(sizeof(struct Node));
    second->data=b[0];
    second->next = NULL;
    last=second;
    for(int i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data = b[i];
        t->next = NULL;
        last->next = t;
        last=t;
    }
}

// void concat(struct Node *p, struct Node *q) 
// {
//     third=p;
//     while(p->next != NULL)
//     {
//         p=p->next;
//     }
//     p->next = q;
// }

void merge(struct Node* p, struct Node* q)
{
    struct Node *last;
    if(p->data < q->data)
    {
        last=third=p;
        p=p->next;
        third->next = NULL;
    }
    else{
        third=last=q;
        q=q->next;
        third->next = NULL;
    }
    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next= NULL;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next= NULL;
        }
        
    }
    if(p)
    last->next=p;
    if(q)
    last->next=q;
    
}

int main()
{
    int a[]={1,3,4,6,7};
    int b[]={2,5,8,9};
    create(a,5);
    create1(b,4);
    // display(first);
    // display(second);
    // concat(first,second);
    merge(first,second);
    display(third);
    return 0; 
}