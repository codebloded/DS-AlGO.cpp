#include <bits/stdc++.h>
using namespace std;

string compression_one(string s)
{
    string res = s.substr(0, 1);
    for (int i = 1; i < s.length(); i++)
    {
        char curr = s.at(i);
        char prev = s.at(i - 1);
        if (curr != prev)
        {
            res = res + curr;
        }
    }
    return res;
}

string compression_two(string s)
{
    string res = s.substr(0, 1);
    int count = 1;
    for (int i = 1; i < s.length(); i++)
    {
        char curr = s.at(i);
        char prev = s.at(i - 1);

        if (curr == prev)
        {
            count++;
        }
        else
        {
            if (count > 1)
            {
                res = res + to_string(count);
                count = 1;
            }
            res = res + curr;
        }
    }
    if (count > 1)
    {
        res = res + to_string(count);
        count = 1;
    }
    return res;
}
int main()
{
    string s;
    cin >> s;
    cout << compression_one(s);
    cout << compression_two(s);

    return 0;
}