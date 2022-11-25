#include <iostream>
using namespace std;

class Queue
{
private:
    int size;
    int rear;
    int front;
    int *Q;

public:
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new int[size];
    }

    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new int[this->size];
    }

    void enqueue(int x);
    int dequeue();
    void display();
};

void Queue::enqueue(int x)
{
    if (rear == size - 1)
        printf("Queue is full\n");
    else
    {
        rear++;
        Q[rear] = x;
    }
}

int Queue::dequeue()
{
    int x=-1;
    if (rear == front == -1)
        printf("Queue is empty\n");

    else
    {
        x = Q[front + 1];
        front++;
    }
    return x;
}

void Queue::display()
{
    for (int i = front + 1; i <= rear; i++)
    {
        printf("%d ", Q[i]);
    }
    printf("\n");
}

int main()
{
    Queue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}