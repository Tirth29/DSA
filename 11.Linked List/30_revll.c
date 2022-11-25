#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;
void Display(struct Node *p)
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

void Reverse1(struct Node *p)
{
    struct Node *q=p;
    int i=0,*a;
    a=(int *)malloc(sizeof(int)*5);
    while(q!=NULL)
    {
        a[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=NULL)
    {
        q->data=a[i];
        q=q->next;
        i--;
    }
}

int main()
{
    int A[] = {10, 20, 40, 50, 60};
    create(A, 5);
    Reverse1(first);
    Display(first);
    return 0;
}