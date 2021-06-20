#include <iostream>
using namespace std;

void reverse(int *arr, int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int(n);
    for (int i = 0; i <= n; i++)
        cin >> arr[i];
    int start = 0;
    int end = n;
    reverse(arr, start, end);
    for (int i = 0; i <= n; i++)
        cout << arr[i];
    return 0;
}