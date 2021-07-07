#include <bits/stdc++.h>
using namespace std;

static string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

vector<string> getKPC(string s)
{
    if (s.length() == 0)
    {
        vector<string> baseRes;
        baseRes.push_back("");
        return baseRes;
    }
    char ch = s.at(0);
    string rest_str = s.substr(1);

    vector<string> recursion_res = getKPC(rest_str);
    vector<string> myres;

    string codes_for_ch = codes[ch - 48];
    for (int i = 0; i < codes_for_ch.length(); i++)
    {
        char char_code = codes_for_ch.at(i);
        for (string r_str : recursion_res)
        {
            myres.push_back(char_code + r_str);
        }
    }
    return myres;
}

int main()
{
    string s;
    cin >> s;

    vector<string> ans = getKPC(s);
    int cnt = 0;

    cout << '[';
    for (string str : ans)
    {
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
    return 0;
}