struct stack
{
    int top;
    int size;
    struct node **S;

};

void stackcreate(struct stack *s,int size)
{
    s->size= size;
    s->top=-1;
    s->S=(struct node **)malloc(s->size*sizeof(struct node  *));

}

void push(struct stack *s,struct node *x)
{
    if(s->top==s->size-1)
        printf("Stack overflow");
    else
    {
        s->top++;
        s->S[s->top]=x;
    }
}

struct node *pop(struct stack *s)
{
    struct node *x= NULL;
    if(s->top==-1)
        printf("Stack underflow");
    else
    {
        x=s->S[s->top--];
    }
    return x;
}

int isemptystk(struct stack s)
{
    if(s.top==-1)
        return 1;
    return 0;
}

int isfull(struct stack *s)
{
    return s->top==s->size-1;
}