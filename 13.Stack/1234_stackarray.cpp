#include <iostream>
using namespace std;

template <class T>
class stack
{
private:
    T *st;
    int size;
    int top;

public:
    stack()
    {
        size = 10;
        top = -1;
        st = new T[size];
    }
    stack(int size)
    {
        this->size = size;
        top = size;
        top = -1;
        st = new T[this->size];
    }

    void push(T x);
    T pop();
    T peek(int index);
    int stacktop();
    int isempty();
    int isfull();
    int display();
};
template <class T>
void stack<T>::push(T x)
{
    if (isfull())
        cout << "Stack overflow" << endl;
    else
    {
        top++;
        st[top] = x;
    }
}

template <class T>
T stack<T>::pop()
{
    int x;
    if (T x = isempty())
        cout << "Stack underflow" << endl;
    else
    {
        x = st[top];
        top--;
    }
    return x;
}

template <class T>
T stack<T>::peek(int index)
{
    T x = -1;
    if (top - index + 1 < 0)
        cout << "Invalid index" << endl;
    else
        x = st[top - index + 1];
    return x;
}

template <class T>
int stack<T>::stacktop()
{
    if (isempty())
        return -1;
    return st[top];
}

template <class T>
int stack<T>::isfull()
{
    return top == size - 1;
}

template <class T>
int stack<T>::isempty()
{
    return top == -1;
}

template <class T>
int stack<T>::display()
{
    for (int i = top; i >= 0; i--)
        cout << st[i] << "\t" << endl;
}

int main()
{
    int x;
    stack<char> stk(5);
    stk.push('a');
    stk.push('b');
    stk.push('c');
    stk.push('d');
    stk.push('e');
    stk.push('f');
    stk.display();
    cout << stk.peek(1) << endl;
    return 0;
    
}