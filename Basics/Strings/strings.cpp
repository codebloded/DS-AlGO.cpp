#include <bits/stdc++.h>
using namespace std;

int main()
{
    // string str = "Hello";
    string str;
    //cin >> str;        // For input a word it breaks after the space comes in sentence and that's why only read the first word of the sentence
    getline(cin, str); //For input a sentence
    cout << str.at(0);
    for (int i = 0; i < str.size(); i++)
    {
        cout << endl
             << str.at(i);
    }
}