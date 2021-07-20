#include <bits/stdc++.h>
using namespace std;

bool isGreater(int arr[], int i, int j)
{
    cout << "Comparing " << arr[i] << " and " << arr[j];
    if (arr[i] < arr[j])
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

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (isGreater(arr, j, j + 1))
            {
                swap(arr, j, j + 1);
            }
            else
            {
                break;
            }
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
    return 0;
}