#include <bits/stdc++.h>
using namespace std;

void get_sum(int arr1[], int arr2[], int n1, int n2)
{
    int sum[n1 > n2 ? n1 : n2];
    int carry = 0;
    int i = n1 - 1;
    int j = n2 - 1;
    int k = sizeof(sum) / sizeof(sum[0]) - 1;

    while (k >= 0)
    {
        //Digit contains three things
        //1.Carry
        //2.arr1[i]
        //3.arr2[j]
        int digit = carry;
        if (i >= 0)
        {
            digit = digit + arr1[i];
        }
        if (j >= 0)
        {
            digit = digit + arr2[j];
        }
        carry = digit / 10;
        digit = digit % 10;

        sum[k] = digit;

        i--;
        j--;
        k--;
    }
    if (carry != 0)
    {
        cout << carry;
    }
    for (int val : sum)
    {
        cout << val << endl;
    }
}

int main()
{
    int n1;
    cin >> n1;
    int n2;
    cin >> n2;
    int arr1[n1];
    int arr2[n2];
    for (int i = 0; i < n1; i++)
    {
        std::cin >> arr1[i];
    }

    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }
    get_sum(arr1, arr2, n1, n2);

    return 0;
}