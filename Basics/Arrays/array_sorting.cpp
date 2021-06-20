#include <iostream>
using namespace std;
//Implementing selection Sort algorithum

void sort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {
        12,
        45,
        67,
    };
    int size = sizeof(arr) / sizeof(int);
    sort(arr, size);

    return 0;
}