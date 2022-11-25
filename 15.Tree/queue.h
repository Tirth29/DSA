// // #include "stdlib.h"
// // #ifndef queue
// // #define queue
// #include <stdio.h>
// #include <stdlib.h>
// struct node
// {
//     struct node *lchild;
//     struct node *rchild;
//     int data;

// };

// struct queue
// {
//     int size;
//     int front;
//     int rear;
//     struct node **qu;
// };

// void create(struct queue *q, int size)
// {
//     q->size = size;
//     q->front = q->rear = 0;
//     q->qu = (struct node **)malloc(q->size * sizeof(struct node *));
// }

// void enqueue(struct node *q, struct node *x)
// {
//     if ((q->rear + 1) % q->size == q->front)
//         printf("queue is Full");
//     else
//     {
//         q->rear = (q->rear + 1) % q->size;
//         q->qu[q->rear] = x;
//     }
// }

// struct node *dequeue(struct queue *q)
// {
//     struct node *x = NULL;
//     if (q->front == q->rear)
//         printf("queue is Empty\n");
//     else
//     {
//         q->front = (q->front + 1) % q->size;
//         x = q->qu[q->front];
//     }
//     return x;
// }

// int isempty(struct queue q)
// {
//     return q.front==q.rear;
// }

struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
};
struct queue
{
    int size;
    int front;
    int rear;
    struct node **Q;
};
void create(struct queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct node **)malloc(q->size * sizeof(struct node *));
}
void enqueue(struct queue *q, struct node *x)
{
    if ((q->rear + 1) % q->size == q->front)
        printf("queue is Full");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}
struct node *dequeue(struct queue *q)
{
    struct node *x = NULL;
    if (q->front == q->rear)
        printf("queue is Empty\n");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}
int isempty(struct queue q)
{
    return q.front == q.rear;
}