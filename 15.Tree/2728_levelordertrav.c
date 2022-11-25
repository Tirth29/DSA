#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"

struct node *root = NULL;

void createtree()
{
    struct node *p,*t;
    int x;
    struct queue q;
    create(&q,100);

    printf("Enter root value : ");
    scanf("%d",&x);

    root = (struct node *)malloc(sizeof(struct node));
    root->data= x;
    root->lchild= root->rchild = NULL;
    enqueue(&q,root);

    while(!isempty(q))
    {
        p= dequeue(&q);
        printf("Enter the left child of %d :", p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct node *)malloc(sizeof(struct node));
            t->data = x;
            t->lchild=t->rchild= NULL;
            p->lchild= t;
            enqueue(&q,t);
        }
        printf("Enter right childe of %d : ", p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct node *)malloc(sizeof(struct node));
            t->data = x;
            t->lchild=t->rchild= NULL;
            p->rchild= t;
            enqueue(&q,t);
        }
    }
}

void levelorder(struct node *p)
{
    struct queue q;
    create(&q,100);
    printf("%d   ",p->data);
    enqueue(&q,p);
    while(!isempty(q))
    {
        p= dequeue(&q);
        if(p->lchild)
        {
            printf("%d   ",p->lchild->data);
            enqueue(&q,p->lchild);
        }
        if(p->rchild)
        {
            printf("%d   ",p->rchild->data);
            enqueue(&q,p->rchild);
        }
    }
}


int main()
{
    createtree();
    printf("\nLevelorder\n");
    levelorder(root);

    return 0;
}