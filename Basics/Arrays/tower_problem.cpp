#include <bits/stdc++.h>
using namespace std;

int get_min_height(int arr[], int length, int k)
{
    //sort the array
    sort(arr, arr + length);
    int max_tower;
    int min_tower;
    int result = arr[length - 1] - arr[0];
    for (int i = 0; i <= length - 1; i++)
    {
        max_tower = max(arr[i - 1] + k, arr[length - 1] - k);
        min_tower = min(arr[0] + k, arr[i] - k);
        result = min(result, max_tower - min_tower);
    }
    return result;
}
int main()
{
    //creating the array
    int arr[] = {2, 6, 3, 4, 7, 2, 10, 3, 2, 1};
    int length = sizeof(arr) / sizeof(arr[0]);
    int k = 5;
    cout << get_min_height(arr, length, k);
    return 0;
}
