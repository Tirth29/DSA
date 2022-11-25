// Inserting in a Sorted Linked List
// #include <stdio.h>
// #include <stdlib.h>
//     struct Node
// {
//     int data;
//     struct Node *next;
// } *first = NULL, *second = NULL, *third = NULL;
// void Display(struct Node *p)
// {
//     while (p != NULL)
//     {
//         printf("%d ", p->data);
//         p = p->next;
//     }
// }
// void create(int A[], int n)
// {
//     int i;
//     struct Node *t, *last;
//     first = (struct Node *)malloc(sizeof(struct Node));
//     first->data = A[0];
//     first->next = NULL;
//     last = first;
//     for (i = 1; i < n; i++)
//     {
//         t = (struct Node *)malloc(sizeof(struct Node));
//         t->data = A[i];
//         t->next = NULL;
//         last->next = t;
//         last = t;
//     }
// }
// void SortedInsert(struct Node *p, int x)
// {
//     struct Node *t, *q = NULL;
//     t = (struct Node *)malloc(sizeof(struct Node));
//     t->data = x;
//     t->next = NULL;
//     if (first == NULL)
//         first = t;
//     else
//     {
//         while (p && p->data < x)
//         {
//             q = p;
//             p = p->next;
//         }
//         if (p == first)
//         {
//             t->next = first;
//             first = t;
//         }
//         else
//         {
//             t->next = q->next;
//             q->next = t;
//         }
//     }
// }

// int main()
// {
//     int A[] = {10, 20, 30, 40, 50};
//     create(A, 5);
//     printf(“% d\n”, SortedInsert(first, 15));
//     Display(first);
//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}*first=NULL;


void display(struct node *p)
{
    while(p)
    {
        printf("%d ", p->data);
        p=p->next;
    }
}

void create(int a[],int x)
{
    struct node *t,*last;
    first=(struct node *)malloc(sizeof(struct node));
    first->data=a[0];
    first->next=NULL;
    last=first;

    for (int i=1; i<x; i++)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void sortedlist(struct node *p,int x)
{
    struct node *t,*q=NULL;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;

    if(first==NULL)
        first=t;
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==NULL)
        {
            t->next=first;
            first=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }

}

int main ()
{
    int a[]={10,20,30,40,50,60};
    create(a,6);
    display(first);
    sortedlist(first,25);
    printf("\n");
    display(first);

}