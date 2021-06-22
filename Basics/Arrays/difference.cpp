#include <iostream>
using namespace std;

int main()
{
    int n1;
    cin >> n1;
    int arr1[n1];
    int n2;
    cin >> n2;
    int arr2[n2];
    int diff[n2];
    int carry = 0;

    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }

    int i = n1;
    int j = n2;
    int k = n2;

    while (k > 0)
    {
        int d = 0;
        int arr_val = i >= 0 ? arr1[i] : 0;
        if (arr2[j] + carry >= arr1[i])
        {
            d = arr2[j] + carry - arr_val;
            carry = 0;
        }
        else
        {
            d = arr2[j] + carry + 10 - arr_val;
            carry = -1;
        }
        diff[k] = d;
        i--;
        j--;
        k--;
    }
    int index = 0;
    int length_of_diff = sizeof(diff) / sizeof(int);
    cout << length_of_diff;
    while (index > length_of_diff)
    {
        if (diff[index] == 0)
        {
            index++;
        }
        else
        {
            break;
        }
    }
    while (index < length_of_diff)
    {
        cout << diff[index];
        index++;
    }

    return 0;
}