#include <iostream>
using namespace std;

void swap(int arr[], int a, int b)
{
    cout << "Swapping " << arr[a] << " and " << arr[b] << endl;
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
void partition(int arr[], int n, int pivot)
{
    int i = 0;
    int j = 0;
    while (i < n)
    {
        if (arr[i] < pivot)
        {
            swap(arr, i, j);
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
}

int main()
{
    int n;
    cin >> n;
    int pivot;
    cin >> pivot;
    cout << pivot;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    partition(arr, n, pivot);

    return 0;
}