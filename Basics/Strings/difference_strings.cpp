#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string ss;
    ss.push_back(s[0]);

    for (int i = 1; i < s.length(); i++)
    {
        char first = s[i - 1];
        char sec = s[i];
        int gap = (char)(sec - first);
        // cout << sec << "ME" << endl;
        // cout << first << "ME" << endl;
        // cout << gap << endl;
        ss.push_back(sec);
        ss.push_back(gap);
        cout
            << ss[i];
    }
    // for (auto i : ss)
    // {
    //     cout << i;
    // }

    return 0;
}
