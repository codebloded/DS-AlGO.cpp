#include <bits/stdc++.h>
using namespace std;

void largestAreaHistogram(int arr[], int n)
{

    stack<int> st;
    int right_bound[n];
    st.push(n - 1);
    right_bound[n - 1] = n;

    for (int i = n - 2; i >= 0; i--)
    {
        while (st.size() > 0 && arr[i] <= arr[st.top()])
        {
            st.pop();
        }
        if (st.size() == 0)
        {
            right_bound[i] = n;
        }
        else
        {
            right_bound[i] = st.top();
        }
        st.push(i);
    }

    int left_bound[n];
    st.push(0);
    left_bound[0] = -1;
    for (int i = 1; i < n; i++)
    {
        while (st.size() > 0 && arr[i] < arr[st.top()])
        {
            st.pop();
        }
        if (st.size() == 0)
        {
            left_bound[i] = -1;
        }
        else
        {
            left_bound[i] = st.top();
        }
        st.push(i);
    }

    //area
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        int width = right_bound[i] - left_bound[i] - 1;
        int area = width * arr[i];
        if (area > maxArea)
        {
            maxArea = area;
        }
    }
    cout << maxArea;
}

int main()
{
    stack<int> stack;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    largestAreaHistogram(arr, n);

    return 0;
}