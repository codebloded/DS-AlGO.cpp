#include <iostream>
using namespace std;

int fib(int n, int dp[])
{
    if (n == 1 || n == 0)
    {
        return n;
    }
    if (dp[n] != 0)
    {
        return dp[n];
    }

    int fibnm1 = fib(n - 1, dp);
    int fibnm2 = fib(n - 2, dp);
    int fibn = fibnm1 + fibnm2;

    dp[n] = fibn;
    return fibn;
}

int main()
{
    int n;
    cin >> n;
    int *dp = new int[n + 1];
    cout << fib(n, dp) << endl;
    return 0;
}