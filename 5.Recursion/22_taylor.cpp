#include <iostream>
using namespace std;

double e(int x,int n)
{
    static double p=1,f=1;
    double r;
    if(n==0)
        return 1;
    r=e(x,n-1);
    p=p*x;
    f=f*n;
  
    return r+p/f;
}

int main()
{
    int x,n;

    cout <<"X : " << endl;
    cin >> x;
    cout <<"N : " << endl;
    cin >> n;

    printf("%0.2lf",e(x,n));

    return 0;
}