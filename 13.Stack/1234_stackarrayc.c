#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *s;
};

void create(struct stack *st)
{
    printf("Enter the size of stack : ");
    scanf("%d", &st->size);
    st->top = -1;
    st->s = (int *)malloc(st->size * sizeof(int));
}

void push(struct stack *st, int x)
{
    if (st->top == st->size - 1)
    {
        printf("Stack is overflow");
    }
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(struct stack *st)
{
    int x = -1;
    if (st->top == -1)
    {
        printf("Stack underflow");
    }
    else
    {
        x = st->s[st->top--];
    }
    return x;
}

int peek(struct stack *st, int i)
{
    int x = -1;
    if (st->top - i + 1 < 0)
    {
        printf("Invalid index");
    }
    else
    {
        x = st->s[st->top - i + 1];
    }
    return x;
}

void display(struct stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
        printf("\n%d", st.s[i]);
    printf("\n");
}

void isempty(struct stack st)
{
    if (st.top == -1)
        printf("Stack is empty");
    else
        printf("Stack is not empty");
    // if(st.top==-1)
    //     return -1;
    // return 0;

}

void isfull(struct stack st)
{
    if (st.top == st.size - 1)
    {

        printf("\nStack is full");
    }
    else
    {

        printf("\nStack is not full");
    }
    // return st.top== st.top-1;
}

// int stacktop(struct stack st)
// {
//     if(!=isempty(st))
//         return st.s[st.top];
//     return -1;
// }

int main()
{
    struct stack st;
    create(&st);

    push(&st,5);
    push(&st,10);
    push(&st,15);
    push(&st,20);

    display(st);

    printf("%d\n", peek(&st, 2));
    printf("%d\n", peek(&st, 1));

    printf("Pop element is %d", pop(&st));

    display(st);

    isempty(st);
    isfull(st);
    return 0;
}