#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class stack
{
private:
    Node *top;

public:
    stack(){top = NULL;};
    void push(int x);
    int pop();
    void display();
};

void stack::push(int x)
{
    Node *t = new Node;
    if (t == NULL)
        cout << "Stack is full " << endl;
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int stack::pop()
{
    int x = -1;
    if (top == NULL)
        cout << "Stack is empty " << endl;

    else
    {
        x = top->data;
        Node *t = top;
        top = top->next;
        delete t;
    }
    return x;
}

void stack::display()
{
    Node *p = top;
    while (p != NULL)
    {
        cout << p->data << " \t ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    st.display();
    cout << st.pop() << endl;
    st.display();
    return 0;
}
