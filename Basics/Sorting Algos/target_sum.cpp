#include <bits/stdc++.h>
using namespace std;

void targetSum(int arr[], int n, int target)
{
    sort(arr, arr + n);
    int l = 0;
    int r = n - 1;
    while (l < r)
    {
        if (arr[r] + arr[l] < target)
        {
            l++;
        }
        else if (arr[r] + arr[l] > target)
        {
            r--;
        }
        else
        {
            cout << arr[l] << ", " << arr[r] << endl;
            l++;
            r--;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    targetSum(arr, n, target);

    return 0;
}