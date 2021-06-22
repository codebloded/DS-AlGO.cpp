#include <bits/stdc++.h>
using namespace std;

int main()
{
    int zeros = 0;
    int ones = 0;
    int twos = 0;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            zeros++;
        else if (arr[i] == 1)
            ones++;
        else
            twos++;
    }
    int k = 0;
    for (int i = 0; i < zeros; i++)
        arr[k++] = 0;
    for (int i = 0; i < ones; i++)
        arr[k++] = 1;
    for (int i = 0; i < twos; i++)
        arr[k++] = 2;
    //printing the array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
