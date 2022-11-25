#include <iostream>
#include <stdio.h>
#include "Qcpp.h"

using namespace std;

class tree
{
    node *root;
    public:
        tree(){
            root=NULL;
        }
        void createtree();
        void preorder(){preorder(root);}
        void preorder(node *p);
        void postorder(){postorder(root);}
        void postorder(node *p);
        void inorder(){inorder(root);}
        void inorder(node *p);
        void levelorder(){levelorder(root);}
        void levelorder(node *p);
        int hieght(){return hieght(root);}
        int hieght(node *root);


};

void tree::createtree()
{
    node *p,*t;
    int x;
    queue q(100);

    cout << "Enter the root value : "<< endl;
    cin >> x;
    root = new node;
    root->data=x;
    root->lchild=root->rchild=NULL;
    q.enqueue(root);

    while(!q.isempty())
    {
        p=q.dequeue();
        cout << "Enter the left child of " << p->data << endl;
        cin >> x;
        if(x!=-1)
        {
            t= new node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            q.enqueue(t);
        }
        cout << "Enter the right child of " << p->data << endl;
        cin >> x;
        if(x!=-1)
        {
            t=new node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            q.enqueue(t);
        }
    }
}

void tree::preorder(struct node *p)
{
    if(p)
    {
        cout<<p->data << "\t";
        preorder(p->lchild);
        preorder(p->rchild);
    }

}

void tree::inorder(struct node *p)
{
    if(p)
    {
        inorder(p->lchild);
        cout<<p->data<<"\t";
        inorder(p->rchild);
    }
}
void tree::postorder(struct node *p)
{
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<"\t";
    }
}

int tree::hieght(struct node *root)
{
    int x=0,y=0;
    if(root==0)
        return 0;
    x=hieght(root->lchild);
    y=hieght(root->rchild);
    if(x>y)
        return x+1;
    else
        return y+1;

}

int main()
{
    tree t;
    t.createtree();
    cout <<"Preorder"<<endl;
    t.preorder();
    cout<<"\nInorder\n";
    t.inorder();
    cout<<"\nPostorder\n";
    t.postorder();
    cout <<"\nHight of the tree is "<< t.hieght()<<endl;



    return 0;
}
