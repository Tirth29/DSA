
#include <iostream>
#include <stdlib.h>

using namespace std;

class node
{
public:
    int data;
    node *next;
};

class ll
{
private:
    node *first;

public:
    ll() { first = NULL; }
    ll(int a[], int n);
    ~ll();

    void display();
    void insert(int index, int n);
    int delete1(int index);
    int length();
};

ll::ll(int a[], int n)
{
    node *last, *t;
    int i = 0;
    first = new node;
    first->data = a[0];
    first->next = NULL;
    last = first;
    for (i = 0; i < n; i++)
    {
        t = new node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

ll::~ll()
{
    node *p = first;
    while (first)
    {
        first = first->next;
        delete (p);
        p = first;
    }
}

void ll::display()
{
    node *p = first;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int ll::length()
{
    node *p = first;
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void ll::insert(int index, int x)
{
    node *t, *p = first;
    if (index < 0 || index > length())
        return;
    t = new node;
    t->data = x;
    t->next = NULL;
    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

int ll::delete1(int index)
{
    node *p, *q = NULL;
    int x = -1;
    if (index < 1 || index > length())
        return -1;
    if (index == 1)
    {
        p = first;
        first = first->next;
        x = p->data;
        delete p;
    }
    else
    {
        p = first;
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}
int main()
{
    int A[]={1,2,3,4,5};
ll l(A,5);
l.insert(3,10);
l.display();

    return 0;
}