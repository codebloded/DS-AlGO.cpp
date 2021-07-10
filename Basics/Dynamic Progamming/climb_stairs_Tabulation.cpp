#include <iostream>
using namespace std;
//This is Tabulation method to solve this dynamic programming problem

int countPathsTab(int n)
{
    int *dp = new int[n + 1];
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            dp[i] = dp[i - 1];
        }
        else if (i == 2)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        else
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    cout << countPathsTab(n);
    return 0;
}