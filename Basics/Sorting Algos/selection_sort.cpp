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
void swap(int arr[], int a, int b)
{
    cout << "Swapping " << arr[a] << " and " << arr[b] << endl;
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minEl = i;
        for (int j = i + 1; j < n; j++)
        {
            if (isSmaller(arr, minEl, j))
            {
                minEl = j;
            }
        }
        swap(arr, minEl, i);
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
    selection_sort(arr, n);
    display(arr, n);
    return 0;
}