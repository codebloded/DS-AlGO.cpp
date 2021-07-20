#include <iostream>

#include <vector>

using namespace std;

void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> mergeTwoSortedArrays(vector<int> &A, vector<int> &B)
{
    if (A.size() == 0 || B.size() == 0)
        return A.size() == 0 ? B : A;

    int n = A.size();
    int m = B.size();
    vector<int> ans(n + m, 0);

    cout << ("Merging these two arrays ") << endl;
    cout << ("left array -> ");
    print(A);
    cout << ("right array -> ");
    print(B);

    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (A[i] < B[j])
            ans[k++] = A[i++];
        else
            ans[k++] = B[j++];
    }

    while (i < n)
        ans[k++] = A[i++];
    while (j < m)
        ans[k++] = B[j++];

    return ans;
}

vector<int> mergeSort(vector<int> &arr, int lo, int hi)
{
    if (lo == hi)
    {
        vector<int> bas(1);
        bas[0] = arr[lo];
        return bas;
    }

    int mid = (lo + hi) / 2;

    vector<int> fsh = mergeSort(arr, lo, mid);
    vector<int> ssh = mergeSort(arr, mid + 1, hi);
    vector<int> fsa = mergeTwoSortedArrays(fsh, ssh);
    return fsa;
}

int main()
{
    int n, m;
    cin >> n;
    vector<int> A(n, 0);
    input(A);
    int hi = n - 1;
    int lo = 0;
    vector<int> ans = mergeSort(A, lo, hi);
    cout << "Sorted Array -> ";
    print(ans);
    return 0;
}