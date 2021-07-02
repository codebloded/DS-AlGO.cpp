#include <iostream>
#include <math.h>
using namespace std;

int powerLogarithmic(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    int xpnb = pow(x, n / 2);
    int xm = xpnb * xpnb;
    if (n % 2 == 1)
    {
        xm = xm * x;
    }
    return xm;
}

int main()
{
    int x, n;
    cin >> x >> n;
    cout << powerLogarithmic(x, n);
}