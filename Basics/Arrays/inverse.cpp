#include <iostream>
using namespace std;

void inverse(int *arr, int n)
{
    int result[n];
    for (int i = 0; i < n; i++)
    {
        int val = arr[i];
        result[val] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    inverse(arr, n);
    return 0;
}

//Time complexity O(n);