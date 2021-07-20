#include <iostream>
using namespace std;

void swap(int arr[], int a, int b)
{
    cout << "Swapping index " << a << " and index " << b << endl;
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
void partition(int arr[], int n)
{
    int i = 0;
    int j = 0;
    while (i < n)
    {
        if (arr[i] == 1)
        {
            i++;
        }
        else
        {
            swap(arr, i, j);
            i++;
            j++;
        }
    }
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
    partition(arr, n);

    return 0;
}