#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 2, 2, 3, 2, 2, 2, 2, 2, 2, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < len; i++)
    {
        arr[arr[i] % len] = arr[arr[i] % len] + len;
    }
    for (int i = 0; i < len; i++)
    {
        if (arr[i] / len > 1)
        {
            cout << i << " ";
        }
    }
    return 0;
}