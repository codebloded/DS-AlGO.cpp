#include<bits/stdc++.h>
using namespace std;
 
// Returns value of Permutation
// Coefficient P(n, k)
int permutationCoeff(int n, int k)
{
    int fact[n + 1];
 
    // Base case
    fact[0] = 1;
 
    // Calculate value
    // factorials up to n
    for(int i = 1; i <= n; i++)
    fact[i] = i * fact[i - 1];
 
    // P(n,k) = n! / (n - k)!
    return fact[n] / fact[n - k];
}
 
// Driver Code
int main()
{
    int n = 10, k = 2;
     
    cout << "Value of P(" << n << ", "
        << k << ") is "
        << permutationCoeff(n, k);
 
    return 0;
}
