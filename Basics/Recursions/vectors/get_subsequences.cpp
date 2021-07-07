#include <iostream>
#include <vector>
using namespace std;

vector<string> gss(string s)
{
    if (s.size() == 0)
    {
        vector<string> base_res;
        base_res.push_back("");
        return base_res;
    }
    char first_ch = s.at(0);
    string rest_str = s.substr(1);

    //make a recursion call for getting the faith of gss(bc);
    vector<string> recursion_str = gss(rest_str);

    //Init a new vector in which the final result is return
    vector<string> my_res;
    //iterate over the recursion_str to update the vector
    for (string rec_str : recursion_str)
    {
        // my_res.insert(my_res.begin(), ' ' + rec_str);
        my_res.push_back("" + rec_str);
    }
    for (string rec_str : recursion_str)
    {
        // my_res.insert(my_res.begin(), 'a' + rec_str);
        my_res.push_back(first_ch + rec_str);
    }
    return my_res;
}

int main()
{
    string s;
    cin >> s;
    vector<string> ans = gss(s);
    cout << '[';
    for (auto i : ans)
    {
        cout << i << ", ";
    }
    cout << ']';
}