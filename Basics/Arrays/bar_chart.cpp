#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    //taking input of an array
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //Getting max of array
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    for (int floor = max; floor >= 1; floor--)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= floor)
            {
                cout << "*\t";
            }
            else
            {
                cout << "\t";
            }
        }
        cout << endl;
    }
    return 0;
}