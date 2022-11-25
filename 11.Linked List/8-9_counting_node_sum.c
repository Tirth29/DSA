#include <stdio.h>

struct node
{
    int data;
    struct node *next;

} *first = NULL;

void create(int A[], int n)
{
    int i;
    struct node *t, *last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
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

void display1(struct node *q)
{
    if (q != NULL)
    {
        printf("%d ", q->data);
        display(q->next);
    }
}

void display2(struct node *r)
{
    if (r != NULL)
    {

        display2(r->next);
        printf("%d ", r->data);
    }
}

int count(struct node *x)
{
    int c = 0;
    while (x != NULL)
    {
        c++;
        x = x->next;
    }
    return c;
}

// int count1(struct node *x)

// {
//     int c=0;
//     while (x!=NULL)
//     {
//     x=x->next;
//     count1(x);
//     c++;
//     }
//     return c;
// }

int count1(struct node *x)
{
    if(x==NULL)
    return 0;
    else 
    return count1(x->next)+1;
}

int sum(struct node *x)
{
    int sum = 0;
    while(x!= NULL)
    {
        sum+=x->data;
        x=x->next;

    }
    return sum;
}

int sum1(struct node *x)
{
    int sum=0;
    if(x!=NULL)
    return sum1(x->next)+x->data;
    else
    return 0;


}

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    create(A, 9);
    // display(first);
    // display1(first);
    // display2(first);
    printf("\nTotal node is %d\n", count(first));
    printf("Total node is %d\n", count1(first));
    printf("Sum of all nodes is %d\n", sum(first));
    printf("Sum of all nodes is %d\n", sum1(first));
    return 0;
}
