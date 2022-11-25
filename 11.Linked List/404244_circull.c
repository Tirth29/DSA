#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

void create(int a[], int n)
{
    int i = 0;
    struct node *t, *last;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = a[0];
    head->next = head;
    last = head;

    for (i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void display(struct node *h)
{
    do
    {
        printf("%d   ", h->data);
        h = h->next;

    } while (h != head);
}

int length(struct node *h)
{
    int len = 0;
    struct node *l;
    l = h;
    do
    {
        l = l->next;
        len++;
    } while (l != head);
    return len;
}

void insert(struct node *p, int x, int pos)
{
    struct node *t;
    int i;
    if (pos < 0 && pos >= length(p))
        return;
    if (pos == 0)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        if (head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            while (p->next != head)
                p = p->next;
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        for(i=0; i<pos-1; i++)
            p=p->next;
        t=(struct node *)malloc(sizeof(struct node));
        t->data=x;
        t->next=p->next;
        p->next=t;

    }
}
// void Rdisplay(struct node *h)
// {
//     static int flag = 0;
//     if (h != head || flag == 0)
//     {
//         flag = 1;
//         printf("%d ", h->data);
//         Rdisplay(h->next);
//     }
//     flag = 0;
// }

int delete(struct node *p,int pos)
{
    struct node *q;
    int i,x;
    if(pos < 0 && pos> length(p)) return -1;
    if(pos==1)
    {
        while(p->next!=head)
            p=p->next;
        x=head->data;
        if(head=p)
        {
                free(head);
                head=NULL;
        }
        else
        {
            p->next=head->next;
            free(head);
            head=p->next;
        }
    }
    else
    {
        for(i=0;i<pos-2;i++)
            p=p->next;
        q=p->next;
        p->next=q->next;
        x=q->data;
        free(q);
    }
    return x;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    create(a, 5);
    display(head);
    printf("Length: %d\n", length(head));

    insert(head, 7, 0);
    display(head);
    printf("\n");
    // Rdisplay(head);
    delete(head,2);
    display(head);
    return 0;
}