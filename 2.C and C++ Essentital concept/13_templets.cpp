#include <stdio.h>
#include <iostream>
using namespace std;

template <class t>
class arrithmatic
{
private:
    t a;
    t b;
public:
    arrithmatic(t a,t b);
    t add();
    t sub();
};
template <class t>
arrithmatic<t>::arrithmatic(t a, t b)
{
    this->a=a;
    this->b=b;

}

template <class t>
t arrithmatic<t>::add()
{
    t c;
    c=a+b;
    return c;

}
template <class t>
t arrithmatic<t>::sub()
{
    t c;
    c=a-b;
    return c;
}


int main()
{
    arrithmatic<int> ar(10,5);
    cout << ar.add()<<endl;
    arrithmatic<float> arr(1.5,1.2);
    cout << arr.add()<<endl;

}