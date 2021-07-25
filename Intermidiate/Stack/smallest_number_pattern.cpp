#include <bits/stdc++.h>
using namespace std;

int main()
{
    string exp;
    cin >> exp;

    stack<int> st;
    int num = 1;
    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp.at(i);
        if (ch == 'd')
        {
            st.push(num);
            num++;
        }
        else
        {
            st.push(num);
            num++;

            while (!st.empty())
            {
                cout << st.top();
                st.pop();
            }
        }
    }
    st.push(num);
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }

    return 0;
}