#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x)
{
    for (int i = 2; i < sqrt(x); i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<int> lis(n);
    int input = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        lis.push_back(input);
    }
    vector<int>::iterator it = lis.begin();
    for (int i = lis.size(); i >= 0; i--)
    {
        cout << i;
        if (isPrime(lis.at(i)) == true)
        {
            lis.pop_back();
        }
    }

    for (int i : lis)
    {
        cout << i;
    }

    return 0;
}