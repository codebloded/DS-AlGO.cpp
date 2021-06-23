#include <iostream>
using namespace std;

int Kadane_algo(int arr[], int length)
{
    //Kadane's Algo
    int current_sum = arr[0];
    int max_sum = arr[0];
    for (int i = 0; i < length; i++)
    {
        if (current_sum >= 0)
        {
            current_sum += arr[i];
        }
        else
        {
            current_sum = arr[i];
        }
        if (current_sum > max_sum)
        {
            max_sum = current_sum;
        }
    }
    return max_sum;
}
int main()
{
    int arr[] = {4, 3 - 2, 6, -14, 7, -1, 4, 5, 7, -10, 2, 9, -10, -5, -9, 6, 1};
    int length = sizeof(arr) / sizeof(arr[0]);
    cout << Kadane_algo(arr, length) << " ";

    return 0;
}