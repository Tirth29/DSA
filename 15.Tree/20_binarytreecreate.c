// #include <stdio.h>
// #include <stdlib.h>
// #include "queue.h"

// struct node *root=NULL;
// void treecreate()
// {
//     struct node *p,*t;
//     int x;
//     struct queue *q;
//     create(&q,100);

//     printf("Enter the root value : ");
//     scanf("%d",&x);
//     root = (struct node *) malloc(sizeof(struct node));
//     root->data = x;
//     root->lchild=root->rchild=NULL;
//     enqueue(&q,root);

//     while(!isempty(*q))
//     {
//         p=dequeue(&q);
//         printf("Enter the left child of %d\n",p->data);
//         scanf("%d",&x);
//         if(x!=-1)
//         {
//             t=(struct node *)malloc(sizeof(struct node));
//             t->data=x;
//             t->lchild=t->rchild=NULL;
//             p->lchild=t;
//             enqueue(&q,t);
//             printf("Enter the right child of the %d :\n",p->data);
//             scanf("%d",&x);
//             if(x!=-1)
//             {
//                 t=(struct node *)malloc(sizeof(struct node));
//                 t->data=x;
//                 t->lchild=t->rchild=NULL;
//                 p->rchild=t;
//                 enqueue(&q,t);
//             }
//         }

//     }

// }
// void preorder(struct node *p)
//     {
//         if(p){

//         printf("%d\n",p->data);
//         preorder(p->lchild);
//         preorder(p->rchild);

//         }
//     }

// int main(){
//     treecreate();
//     preorder(root);

//     return 0;

// }

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
struct node *root = NULL;
void Treecreate()
{
    struct node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);
    printf("Eneter root value ");
    scanf("%d", &x);
    root = (struct node *)malloc(sizeof(struct node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);
    while (!isEmpty(q))
    {
        p = dequeue(&q);
        printf("eneter left child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct node *)malloc(sizeof(struct
                                             node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("eneter right child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct node *)malloc(sizeof(struct
                                             node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}
void Preorder(struct node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
void Inorder(struct node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}
void Postorder(struct node *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}

int main()
{
    Treecreate();
    printf("Preorder\n");
    Preorder(root);
    printf("\nInorder\n");
    Inorder(root);
    printf("\nPost Order\n");
    Postorder(root);
    return 0;
}
