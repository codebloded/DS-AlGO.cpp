#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int data;
    cin >> data;

    int low = 0;
    int high = n - 1;
    int ciel = 0;
    int floor = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (data > arr[mid])
        {
            mid = low + 1;
            // ciel = arr[high];
            // floor = arr[low];
        }
        else if (data < arr[mid])
        {
            high = mid - 1;
            // ciel = arr[low];
            // floor = arr[high];
        }
        else
        {
            cout << mid;
            break;
        }
    }
    // cout << ciel << " " << floor;
    return 0;
}