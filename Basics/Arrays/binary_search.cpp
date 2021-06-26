#include <iostream>
#include <climits>
using namespace std;

void binary_search(int arr[], int len, int data)
{
    int low = 0;
    int high = len - 1;
    int ciel = INT_MAX;
    int floor = INT_MIN;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (data > arr[mid])
        {
            low = mid + 1;
            ciel = arr[high];
            floor = arr[low];
        }
        else if (data < arr[mid])
        {
            high = mid - 1;
            ciel = arr[low];
            floor = arr[high];
        }
        else
        {
            cout << "FOUND AT " << mid;
            return;
        }
    }
    cout << floor << " " << ciel;
}
int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110};
    int len = sizeof(arr) / sizeof(arr[0]);
    int data = 45;
    binary_search(arr, len, data);
    return 0;
}