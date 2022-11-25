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

int leafcount(struct node *p)
{
    int x=0,y=0;
    if(p!=NULL)
    {
        x=leafcount(p->lchild);
        y=leafcount(p->rchild);
        if(!p->rchild && !p->rchild)
            return 1;
        return x+y;
    }
}

int deg2node(struct node *p)
{
    int x=0,y=0;
    if(p!=NULL)
    {
        x=deg2node(p->lchild);
        y=deg2node(p->rchild);
        if(p->rchild && p->rchild)
            return x+y+1;
        return x+y;
    }
}

int deg1or2(struct node *p)
{
    int x=0,y=0;
    if(p!=NULL)
    {
        x=deg1or2(p->lchild);
        y=deg1or2(p->rchild);
        if(p->rchild || p->lchild)
            return x+y+1;
        return x+y;
    }
}

int deg1(struct node *p)
{
    int x=0,y=0;
    if(p!=NULL)
    {
        x=deg1(p->lchild);
        y=deg1(p->rchild);
        if((p->rchild && !p->rchild)||(!p->rchild && p->lchild))
            return x+y+1;
        return x+y;
    }
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
    printf("Total number node is %d\n leaf node is %d\n degree 2 node is %d\n degree 1 or 2 node is %d\n degre 1 node is %d\n Height of the tree is %d\n",count(root),leafcount(root),deg2node(root),deg1or2(root),deg1(root),height(root)-1);

    return 0;
}


