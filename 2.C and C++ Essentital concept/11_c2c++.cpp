#include <iostream>
using namespace std;

class rectangle{

    private:
        int length;
        int breadth;

    public:

    rectangle(int a, int b)
    {
        length = a;
        breadth = b;
    }
    int area()
    {
        return length*breadth;
    }
    void changelength(int l)
    {
        length = l;
    }


};

int main(){
    rectangle r(10,5);
    cout<< "Area is " << r.area() << endl;
    r.changelength(20);
    cout<< "Area is " << r.area() << endl;

}