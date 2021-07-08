#include <bits/stdc++.h>
using namespace std;

vector<string> get_stair_pairs(int n)
{
    if (n == 0)
    {
        vector<string> base_res;
        base_res.push_back("");
        return base_res;
    }
    else if (n < 0)
    {
        vector<string> base_res;
        return base_res;
    }

    vector<string> path1 = get_stair_pairs(n - 1);
    vector<string> path2 = get_stair_pairs(n - 2);
    vector<string> path3 = get_stair_pairs(n - 3);

    vector<string> paths;

    for (string path : path1)
    {
        paths.push_back("1" + path);
    }
    for (string path : path2)
    {
        paths.push_back("2" + path);
    }
    for (string path : path3)
    {
        paths.push_back("3" + path);
    }
    return paths;
}

int main()
{
    int n;
    cin >> n;
    vector<string> ans = get_stair_pairs(n);
    for (auto i : ans)
    {
        cout << i;
    }
    return 0;
}