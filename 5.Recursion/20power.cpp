#include <iostream>

using namespace std;

int power(int n,int p)
{
    if(p==0)
        return 1;
    else
        return (power(n,p-1)*n);
}

int main()
{
    int number,pow;
    cout << "Enter a number : "<< endl;
    cin >> number;
    cout << "Enter a power : "<< endl;
    cin >> pow;

    cout<< number<<"^"<<pow<<"="<<power(number,pow) << endl;

    return 0;
}