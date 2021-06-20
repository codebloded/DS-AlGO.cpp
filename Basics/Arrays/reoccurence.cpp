#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int element;
    cout << "Enter Element" << endl;
    cin >> element;
    int counter = 0;
    int arr[n];
    for (int i = 0; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i <= n; i++)
    {
        if (arr[i] == element)
        {
            counter++;
        }
    }
    cout << counter << endl;
    return 0;
}