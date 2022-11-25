#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h" 

struct node *root = NULL;

void createtree()
{
    struct node *p,*t;
    int x;
    struct queue q;
    create(&q, 100);

    printf("Enter root value: \n");
    scanf("%d", &x);

    root=(struct node *)malloc(sizeof(struct node));
    root->data=x;
    root->lchild= root->rchild = NULL;
    enqueue(&q,root);

    while(!isempty(q))
    {
        p=dequeue(&q);
        printf("Enter left child of %d\n",p->data);
        scanf("%d", &x);
        if(x!=-1)
        {
        t=(struct node *)malloc(sizeof(struct node));

        t->data=x;
        t->lchild=t->rchild =NULL;
        p->lchild=t;
        enqueue(&q,t);
        }
        printf("Enter right child of %d \n",p->data);
        scanf("%d", &x);
        if(x!=-1)
        {
            t= (struct node *)malloc(sizeof(struct node));
            t->data=x;
            t->rchild=t->lchild =NULL;
            p->rchild=t;
            enqueue(&q,t);

        }

    }
}

// void preorder(struct node *p)
// {
//     struct stack st;
//     stackcreate(&st,100);

//     while(p || !isemptystk(st))
//     {
//         if(p)
//         {
//             printf("%d   ", p->data);
//             push(&st,p);
//             p=p->lchild;
//         }
//         else
//         {
//             p=pop(&st);
//             p=p->rchild;
//         }
//     }
// }

// void inorder(struct node *p)
// {
//     struct stack st;
//     stackcreate(&st,100);
//     while(p || !isemptystk(st))
//     {
//         if(p)
//         {
//             push(&st,p);
//             p=p->lchild;
//         }
//         else
//         {
//             p=pop(&st);
//             printf("%d   ",p->data);
//             p=p->rchild;
//         }
//     }

// }

int count(struct node *p)
{
    if(p)
        return count(p->lchild)+count(p->rchild)+1;
    return 0;
}

int height(struct node *root)
{
    int x=0,y=0;
    if(root==0)
        return 0;
    x=height(root->lchild);
    y=height(root->rchild);
    if(x>y)
        return x+1;
    return  y+1;
}

int main()
{
    createtree();
    printf("Total number of node is %d and height of the tree is %d\n",count(root),height(root)-1);

    return 0;
}


