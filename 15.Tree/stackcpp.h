#include <iostream>
#include "Qcpp.h"
using namespace std;

class Node
{
    public:
        Node *lchild;
        int data;
        Node *rchild;
};

class stack
{
    private:
        int top;
        int size;
        Node **S;
    public:
        stack()
        {
            top=-1;
            size=100;
            S=new Node*[size];
        }

        stack(int size)
        {
            top=size;
            this->size=size;
            S=new Node*[size];
        }
        void create_stack(struct stack *s,int size);
        void push(struct stack *s,struct Node *x);
        Node* pop(struct stack *s);
        int isempty(struct stack *s);
        int isfull(struct stack *s);

};


void stack::create_stack(struct stack *s,int size)
{
    s->size = size;
    s->top = -1;
    s->S=(struct Node **)malloc(s->size * sizeof(struct Node *));
}

void stack::push(struct stack *s,struct Node *x)
{
    if(s->top == s->size-1)
        cout << "Stack overflow " <<endl;
    else
    {
        s->top++;
        s->S[s->top] = x;
    }

}

Node* stack::pop(struct stack *s)
{
    struct Node *x = NULL;
    if(s->top==-1)
        cout << "Stack underflow " <<endl;
    else{
        x=s->S[s->top--];
    }
    return x;
}

int stack::isempty(struct stack *s)
{
    if(top==-1)
        return 1;
    return 0;
}

int stack::isfull(struct stack *s)
{
    return top==size-1;   
}