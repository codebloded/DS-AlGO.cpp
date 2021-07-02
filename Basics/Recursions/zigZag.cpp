#include <iostream>
using namespace std;

void pzz(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << " "; //Printing
    pzz(n - 1);       //left call()
    cout << n << " "; //center call
    pzz(n - 1);       //right call()
    cout << n << " ";
}

int main()
{
    int n;
    cin >> n;
    pzz(n);
}
