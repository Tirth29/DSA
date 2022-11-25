#include <iostream>
using namespace std;
#include <stdlib.h>
class node 
{
    public:
        node *lchild;
        int data;
        node *rchild;
};

class queue
{
    private:
        int front;
        int rear;
        int size;
        node **Q;
    public:
        queue()
        {
            front=rear=-1;
            size=100;
            Q=new node*[size];

        }

        queue(int size)
        {
            front=rear=size;
            this->size=size;
            Q=new node*[this->size];
        }
        void enqueue(node *x);
        node* dequeue();
        void display();
        int isempty(){return front==rear;}

};

void queue::enqueue(node *x)
{
    if(rear==size-1)
        cout << "queue is full" << endl;
    else
    {
        rear++;
        Q[rear]=x;
    }
}

node* queue::dequeue()
{
    node* x=nullptr;
    if(front==rear)
        // cout<<"Queue is empty!";
        printf("Queue is empty!\n");
    else
    {
        x=Q[front+1];
        front++;
    }
    return x;
}

