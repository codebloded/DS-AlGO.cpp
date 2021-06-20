#include <iostream>
using namespace std;

bool search_number(int *arr, int size, int number)
{
    for (int i = 0; i <= size; i++)
    {
        if (arr[i] == number)
            return true;
    }
    return false;
}

int main()
{
    int n;
    int number;
    cout << "Enter the size of array \n";
    cin >> n;
    cout << "Enter the element \n";
    cin >> number;
    int *arr = new int(n);
    //Entering the values by user
    for (int i = 0; i <= n; i++)
    {
        cin >> arr[i];
    }
    //Printing the values
    for (int i = 0; i <= n; i++)
    {
        cout << arr[i];
    }
    cout << "\n"
         << search_number(arr, n, number);

    delete (arr);
    return 0;
}