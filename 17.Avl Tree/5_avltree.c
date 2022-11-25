// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//     /* data */
//     struct node *lchild;
//     struct node *rchild;
//     int data;
//     int height;
// }*root=NULL;

// int nodeheight(struct node *p)
// {
//     int hl,hr;
//     hl=p && p->lchild?p->lchild->height:0;
//     hr=p && p->lchild?p->lchild->height:0;

//     return hl>hr?hl+1:hr+1;
// }

// int balanceFactor(struct node *p)
// {
//     int hl,hr;
//     hl=p && p->lchild?p->lchild->height:0;
//     hr=p && p->lchild?p->lchild->height:0;
//     return hr-hl;
// }

// struct node *LLrotation(struct node *p)
// {
//     struct node *pl=p->lchild;
//     struct node *plr=pl->rchild;

//     pl->rchild=p;
//     p->lchild=plr;
//     p->height=nodeheight(p);
//     pl->height=nodeheight(pl);
//     if(root==p)
//         root=pl;
//     return pl;
// }

// struct node *LRrotation(struct node *p)
// {
//     struct node *pl=p->lchild;
//     struct node *plr=pl->rchild;

//     pl->rchild=plr->lchild;
//     p->lchild=pl->rchild;

//     plr->lchild=pl;
//     plr->rchild=p;

//     p->height=nodeheight(p);
//     pl->height=nodeheight(pl);
//     plr->height=nodeheight(plr);

//     if(root==p)
//         root=plr;
//     return plr;

// }

// struct node *RRrotation(struct node *p)
// {
//     return NULL;
// }

// struct node *RLrotation(struct node *p)
// {
//     return NULL;
// }

// struct node *RInsert(struct node *p,int x)
// {
//     struct node *t=NULL;
//     if(p==NULL)
//     {
//         t=(struct node *)malloc(sizeof(struct node));
//         t->data=x;
//         t->height=1;
//         t->lchild=t->rchild=NULL;
//         return t;
//     }

//     if(x < p->data)
//         p->lchild=RInsert(p->lchild,x);
//     else if(x > p->data)
//         p->rchild=RInsert(p->rchild,x);
//     p->height = nodeheight(p);

//     if(balanceFactor(p)==2 && balanceFactor(p->lchild==1))
//         return LLrotation(p);
//     else if(balanceFactor(p)==2 && balanceFactor(p->lchild==-1))
//         return LRrotation(p);
//     else if(balanceFactor(p)==-2 && balanceFactor(p->lchild==-1))
//         return RRrotation(p);
//     else if(balanceFactor(p)==-2 && balanceFactor(p->lchild==1))
//         return RLrotation(p);
//     return p;
// }

// void Inorder(struct node *p)
// {
//     if (p)
//     {
//         Inorder(p->lchild);
//         printf("%d ", p->data);
//         Inorder(p->rchild);
//     }
// }

// int main()
// {
//     root=RInsert(root,50);
//     RInsert(root,10);
//     RInsert(root,20);
//     Inorder(root);

//     return  0;
// }

#include <stdio.h>
#include <stdlib.h>
    struct Node
{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
} *root = NULL;
int NodeHeight(struct Node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;
    return hl > hr ? hl + 1 : hr + 1;
}
int BalanceFactor(struct Node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;
    return hl - hr;
}
struct Node *LLRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;
    pl->rchild = p;
    p->lchild = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    if (root == p)
        root = pl;
    return pl;
}
struct Node *LRRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;
    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);
    if (root == p)
        root = plr;
    return plr;
}
struct Node *RRRotation(struct Node *p)
{
    return NULL;
}
struct Node *RLRotation(struct Node *p)
{
    return NULL;
}
struct Node *RInsert(struct Node *p, int key)
{
    struct Node *t = NULL;
    if (p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if (key > p->data)
        p->rchild = RInsert(p->rchild, key);
    p->height = NodeHeight(p);
    if (BalanceFactor(p) == 2 && BalanceFactor(p -> lchild) == 1)
        return LLRotation(p);
    else if (BalanceFactor(p) == 2 && BalanceFactor(p -> lchild) == -1)
        return LRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p -> rchild) == -1)
        return RRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p -> rchild) == 1)
        return RLRotation(p);
    return p;
}
void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}
int main()
{
    root = RInsert(root, 50);
    RInsert(root, 10);
    RInsert(root, 20);
    Inorder(root);
    return 0;
}