#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int low = 0;
    int high = s.size() - 1;

    while (high > low)
    {
        if (s[low++] != s[high--])
        {
            cout << "String is not palindrom" << endl
                 << s;
            break;
        }
    }
    return 0;
}