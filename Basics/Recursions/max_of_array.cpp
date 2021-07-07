#include <iostream>
using namespace std;

int max(int arr[], int idx, int n)
{
    if (idx > n - 1)
    {
        return -1;
    }
    int maximum_in_small = max(arr, idx + 1, n);
    if (maximum_in_small > arr[idx])
    {
        return maximum_in_small;
    }
    else
    {
        return idx;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int p = max(arr, 0, n);
    cout << p << endl;
}