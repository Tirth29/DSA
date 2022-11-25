#include <iostream>
#include <stdlib.h>
#include "stackcpp.h"
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

    cout << "Enter the root value : " << endl;
    cin >> x;
    root = new node;
    root->data = x;
    root->lchild=root->rchild=NULL;
    q.enqueue(root);

    while(!q.isempty())
    {
        p=q.dequeue();
        cout << "Enter the left child of " <<p->data << endl;
        cin >> x;
        if(x!=-1)
        {
            t=new node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            q.enqueue(t);
        }

        cout << "Enter the right child of " <<p->data << endl;
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
    struct stack st;
    st.create_stack(&st,100);

    while(p || !st.isempty(&st))
    {
        if(p)
        {
            printf("%d\t",p->data);
            st.push(&st,p);
            p=p->lchild;
        }
        else
        {
            p=st.pop(&st);
            p=p->rchild;
        }

    }

}

int main()
{
    tree t;
    t.createtree();
    cout <<"Preorder"<<endl;
    t.preorder();


    return 0;
}