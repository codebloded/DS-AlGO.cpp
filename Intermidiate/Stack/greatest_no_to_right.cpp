#include <bits/stdc++.h>
using namespace std;

void display(int ans[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }
}
int main()
{
    stack<int> st;
    int n;
    cin >> n;
    int arr[n];
    int ngr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    st.push(arr[n - 1]);
    ngr[n - 1] = -1;

    for (int i = n - 2; i >= 0; i--)
    {
        while (st.size() > 0 && arr[i] >= st.top())
        {
            st.pop();
        }

        if (st.size() == 0)
        {
            ngr[i] = -1;
        }
        else
        {
            ngr[i] = st.top();
        }
        st.push(arr[i]);
    }

    display(ngr, n);

    return 0;
}