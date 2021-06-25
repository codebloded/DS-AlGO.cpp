#include <iostream>
using namespace std;

int main()
{
    int n1, n2;
    cin >> n1;
    int *a1 = new int[n1];
    for (int i = 0; i < n1; i++)
    {
        cin >> a1[i];
    }

    cin >> n2;
    int *a2 = new int[n2];
    for (int i = 0; i < n2; i++)
    {
        cin >> a2[i];
    }

    int diff[n2];
    int i = n1 - 1;
    int j = n2 - 1;
    int carry = 0;
    int k = n2 - 1;
    while (k >= 0)
    {
        int a1_val = i >= 0 ? a1[i] : 0;
        int d = 0;
        if (a2[j] + carry >= a1_val)
        {
            d = a2[j] + carry - a1_val;
            carry = 0;
        }
        else
        {
            d = a2[j] + carry + 10 - a1_val;
            carry = -1;
        }
        diff[k] = d;
        i--;
        j--;
        k--;
    }
    int idx = 0;
    int length_of_diff = sizeof(diff) / sizeof(diff[0]);
    while (idx < length_of_diff)
    {
        if (diff[idx] == 0)
        {
            idx++;
        }
        else
        {
            break;
        }
    }
    while (idx < length_of_diff)
    {
        cout << diff[idx] << endl;
        idx++;
    }

    return 0;
}