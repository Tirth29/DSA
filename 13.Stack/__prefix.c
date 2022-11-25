#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data;
    struct Node *next;
} *top = NULL;

void push(char x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("stack is full\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}
char pop()
{
    struct Node *t;
    char x = -1;
    if (top == NULL)
        printf("Stack is Empty\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}
void Display()
{
    struct Node *p;
    p = top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int isBalanced(char *exp)
{
    int i;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '('|| exp[i]=='{'|| exp[i] == '[')
            push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (top == NULL)
                return 0;
            pop();
        }
    }
    if (top == NULL)
        return 1;
    else
        return 0;
}

int pre(char x)
{
    if(x=='+' || x=='-' )
        return 1;
    else if(x=='/' || x=='*')
        return 2;

    return 0;
}

int isoperand(char x)
{
    if(x=='+' || x=='-' || x=='/' || x=='*') 
        return 0;
    else 
        return 1;
}

char *intoprefix(char *infix)
{
    int i=0,j=0;
    char *prefix;
    int len=strlen(infix);
    prefix=(char *)malloc((len+1)*sizeof(char));

    while(infix[i]!='\0')
    {
        if(isoperand(infix[i]))
            prefix[j++]=infix[i++];
        else
        {
            if(pre(infix[i])>=pre(top->data))
                push(infix[i++]);
            else
            {
                prefix[j++]=pop();
            }
        }
    }
    while(top!=NULL)
        prefix[j++]=pop();
    prefix[j]='\0';
    return prefix;

}



int main()
{
    char *infix;
    printf("Enter a string : ");
    gets(infix);
    push('#');
    infix=strrev(infix);
    char *prefix=intoprefix(infix);
    prefix=strrev(prefix);
    printf("%s  ", prefix);
}


