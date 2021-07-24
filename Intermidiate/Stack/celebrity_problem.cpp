#include <bits/stdc++.h>
using namespace std;

void celebrity(int n)
{
    int arr[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }

    while (st.size() >= 2)
    {

        int i = st.top();
        st.pop();
        int j = st.top();
        st.pop();
        if (arr[i][j] == 1)
        {
            //if i knows j then i is not the celebrity
            st.push(i);
        }
        else
        {
            //if i doest not knows j then j is not the celebrity
            st.push(j);
        }
    }

    int pot = st.top();
    st.pop();

    for (int i = 0; i < n; i++)
    {
        if (i != pot)
        {

            if (arr[i][pot] == 0 || arr[pot][i] == 1)
            {
                cout << "none";
                return;
            }
        }
    }
    cout << pot;
}

int main()
{
    int n;
    cin >> n;
    celebrity(n);
    return 0;
}
