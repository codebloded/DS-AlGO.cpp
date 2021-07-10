#include <iostream>
using namespace std;
//This is memoized method to solve this dynamic programming problem

int countPaths(int n, int dp[])
{
    if (n == 0)
    {
        return 1;
    }
    else if (n < 0)
    {
        return 0;
    }
    if (dp[n] > 0)
    {
        return dp[n];
    }
    int nm1 = countPaths(n - 1, dp);
    int nm2 = countPaths(n - 2, dp);
    int nm3 = countPaths(n - 3, dp);
    int cp = nm1 + nm2 + nm3;
    dp[n] = cp;
    return cp;
}

int main()
{
    int n;
    cin >> n;
    int *dp = new int[n + 1];
    cout << countPaths(n, dp);
    return 0;
}