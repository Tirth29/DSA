#include <iostream> 
using namespace std;

class rectangle
{
    private:
        int length;
        int breadth;

    public:
        rectangle();
        rectangle(int x, int y);
        int area();
        int perimeter();
        int getlength();
        int setlength();
        ~rectangle();
};

rectangle::rectangle(int x, int y)
{
    length=x;
    breadth=y;

}

int rectangle::area()
{
    return length*breadth;
}

int rectangle::perimeter()
{
    return 2*(length+breadth);
}

rectangle::~rectangle()
{

}
// int rectangle::setlength(int l)
// {
//     length=l;
// }
int rectangle::getlength()
{
    return length;
}

int main()
{
    rectangle r(10,5);
    cout<<r.area()<<endl;
    cout<<r.perimeter()<<endl;
    // r.setlength(20);
    cout<<r.getlength()<<endl;
}