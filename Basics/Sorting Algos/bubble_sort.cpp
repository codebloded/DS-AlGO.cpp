#include <bits/stdc++.h>
using namespace std;

bool isSmaller(int arr[], int y, int x)
{
    cout << "Comparing " << arr[x] << " and " << arr[y] << endl;
    if (arr[x] < arr[y])
    {
        return true;
    }
    else
    {
        return false;
    }
}

void bubble_sort(int arr[], int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (isSmaller(arr, j, j + 1))
            {
                cout << "Swapping " << arr[i] << " and " << arr[j] << endl;
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
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
    bubble_sort(arr, n);
    display(arr, n);
    return 0;
}