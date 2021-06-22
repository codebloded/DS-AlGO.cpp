#include <bits/stdc++.h>
using namespace std;

void print_union(int arr1[], int arr2[], int m, int n)
{
    int i = 0;
    int j = 0;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
        }
        else if (arr2[j] < arr1[i])
        {
            cout << arr2[j] << " ";
            j++;
        }
        else
        {
            cout << arr2[j] << " ";
            j++;
            i++;
        }
    }
    while (i < m)
    {
        cout << arr1[i++] << " ";
    }
    while (j < n)
    {
        cout << arr2[j++] << " ";
    }
}

void print_intersectoion(int arr1[], int arr2[], int m, int n)
{
    int i = 0;
    int j = 0;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            cout << arr2[j] << " ";
            i++;
            j++;
        }
    }
}

int main()
{
    int arr1[] = {1, 2, 4, 5, 6};
    int arr2[] = {2, 3, 5, 7};
    int arr1_size = sizeof(arr1) / sizeof(arr1[0]);
    int arr2_size = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Union" << endl;
    print_union(arr1, arr2, arr1_size, arr2_size);
    cout << endl;
    cout << "Intersection" << endl;
    print_intersectoion(arr1, arr2, arr1_size, arr2_size);
    return 0;
}