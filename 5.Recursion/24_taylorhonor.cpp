#include <iostream>
using namespace std;

double e(int x, int n)
{
    static double s = 1;
    if (n == 0)
        return s;
    else
    {
        s = 1 + s / n * x;
        return e(x, n - 1);
    }
}

int main()
{
    int x, n;

    cout << "X : " << endl;
    cin >> x;
    cout << "N : " << endl;
    cin >> n;

    printf("%0.2lf", e(x, n));

    return 0;
}