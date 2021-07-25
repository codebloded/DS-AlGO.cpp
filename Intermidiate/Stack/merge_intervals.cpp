#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> inter;
    for (int i = 0; i < n; i++)
    {
        int start;
        int end;
        cin >> start >> end;
        inter.push_back(make_pair(start, end));
    }
    //sorting the vector of pairs
    sort(inter.begin(), inter.end());

    stack<pair<int, int>> stk;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            stk.push(inter.at(i));
        }
        else
        {
            pair<int, int> top = stk.top();

            if (inter.at(i).first > top.second)
            {
                stk.push(inter.at(i));
            }
            else
            {

                top.second = max(top.second, inter.at(i).second);
                stk.pop();
                stk.push(top);
            }
        }
    }
    stack<pair<int, int>> temp;
    while (stk.size() > 0)
    {
        pair<int, int> top = stk.top();
        stk.pop();
        temp.push(top);
    }

    while (temp.size() > 0)
    {
        pair<int, int> top = temp.top();
        temp.pop();
        cout << top.first << " " << top.second << endl;
    }

    return 0;
}