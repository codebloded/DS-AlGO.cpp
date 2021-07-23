#include <bits/stdc++.h>
using namespace std;

void slidingWindowMax(int arr[], int n, int k)
{
    //Next Greatest element
    stack<int> st;
    int nge[n];
    st.push(n - 1);
    nge[n - 1] = n;
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.size() > 0 && arr[i] >= arr[st.top()])
        {
            st.pop();
        }
        if (st.size() == 0)
        {
            nge[i] = n;
        }
        else
        {
            nge[i] = st.top();
        }
        st.push(i);
    }
    //Sliding window max

    for (int i = 0; i <= n - k; i++)
    {
        int j = i;
        while (nge[j] < i + k)
        {
            j = nge[j];
        }
        cout << arr[j] << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    slidingWindowMax(arr, n, k);
    return 0;
}