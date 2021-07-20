#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeTwoSortedArrays(vector<int> &A, vector<int> &B)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int n = A.size();
    int m = B.size();
    vector<int> res(n + m);

    while (i < n && j < m)
    {
        if (A[i] < B[j])
        {
            res[k] = A[i];
            i++;
            k++;
        }
        else
        {
            res[k] = B[j];
            j++;
            k++;
        }
    }
    while (i < n)
    {
        res[k] = A[i];
        i++;
        k++;
    }
    while (j < m)
    {
        res[k] = B[j];
        j++;
        k++;
    }
    return res;
}

void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

void output(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    int n, m;
    cin >> n;
    vector<int> A(n, 0);
    input(A);

    cin >> m;
    vector<int> B(m, 0);
    input(B);

    vector<int> ans = mergeTwoSortedArrays(A, B);
    output(ans);
    return 0;
}