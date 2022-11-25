#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *first = NULL;
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
void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int Delete(struct Node *p,  int x)
{
    struct Node *q=NULL;
    int a=-1,i;
    if(x<1)
     return -1;
    
    if(x==1)
    {
        q=first;
        a=first->data;
        first=first->next;
        free(q);
        return a;

    }
    else
    {
        for(i=0;i<x-1;i++)
        {
            q=p;
            p=p->next;

        }
        q->next=p->next;
        a=p->data;
        free(p);
        return a;
    }


}
int main()
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    Display(first);
    printf("\n");
    printf("%d\n",Delete(first,2));
    printf("\n");
    Display(first);
    return 0;

    printf(" ")
}
