#include <stdio.h>

struct node
{
    int data;
    struct node *next;

}*first = NULL;

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

int max(struct node *p)
{
    int max=-32432;
    while(p)
    {
        if(p->data>max)
            max=p->data;
            p=p->next;
    }

    return max;

}

int max1(struct node *p)
{
    int max=-32423,x=0;
    if(p==NULL) 
    return max;
    else
    max=max1(p->next);        
    return max>p->data?max:p->data;

}

int search(struct node *p,int x)
{

    while (p!=NULL)
    {
        if(x==p->data)
            return p->data;
        p=p->next;
    }
    return NULL;
    
}

// int search(struct node *p,int x)
// {
//     if(p==NULL)
//     return NULL;
//     if(x==p->data)
//     return p;
//     return search(p->next,x);
// }

struct node *lsearch(struct node * p, int x)
{
    struct node *q=NULL;
    while(p!=NULL)
    {
        if(x==p->data)
        {
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}


int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    create(A, 9);
    display(first);

    printf("Maximum number is %d\n", max(first));
    printf("Maximum number is %d\n", max1(first));
    int x;
    printf("Enter a number to search: ");
    scanf("%d",&x);
    
    if(search(first,x)==0)
    {
        printf("%d is absent\n",x);
    }
    else
    {
    printf("%d is present",x);
   }

   struct node *a;
   a=lsearch(first,5);
   if(a)
   
    printf("\n%d is present\n",a->data);
   
   else 
  
    printf("%d is not present\n",a->data);
  
   display(first);




   return 0;
}