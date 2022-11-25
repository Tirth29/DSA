#include <stdio.h>
struct rectangle
{
    int length;
    int breadth;
};
void intialize(struct rectangle *r, int a,int b)
{
    r->length=a;
    r->breadth=b;

}

int area(struct rectangle r)
{
    return r.length*r.breadth;
}

void changelength(struct rectangle *r, int l)
{
    r->length = l;
}

int main ()
{
    struct rectangle r;
    intialize(&r,10,5);
    int are=area(r);
    printf("Area is %d\n",are);
    changelength(&r,20);
    printf("Area is %d\n",area(r));
    return 0;

}