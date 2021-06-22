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
void rotate(int *arr, int k, int length)
{
    k = k % length;
    if (k < 0)
    {
        k = k + length;
    }
    //Part 1
    reverse(arr, 0, length - k - 1);
    //part 2
    reverse(arr, length - k, length);
    //whole array reverse
    reverse(arr, 0, length - 1);
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int(n);
    for (int i = 0; i <= n; i++)
    {
        cin >> arr[i];
    }
    int start = 0;
    int end = n;
    int k = 3;
    rotate(arr, k, n);
    int i = 0;
    while (i <= n)
    {
        cout << arr[i] << ' ';
        i++;
    }
}
//Time Complexity : O(n);