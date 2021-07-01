#include <iostream>
using namespace std;

int main()
{
    string str;
    cin >> str;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        cout << str.at(i);
    }
    str.reserve(); //Function for reverse a string
    cout << endl
         << str;
    return 0;
}