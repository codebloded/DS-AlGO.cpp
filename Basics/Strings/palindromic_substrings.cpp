#include <iostream>
using namespace std;

bool isPalindrome(string ss)
{
    int low = 0;
    int len = ss.size();
    int high = len;

    while (high >= low)
    {
        if (ss.at(low) != ss.at(high))
        {
            return false;
        }
        else
        {
            low++;
            high--;
        }
    }
    return true;
}

int main()
{

    string str;

    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = i; j <= str.length(); j++)
        {
            string ss = str.substr(i, j);
            if (isPalindrome(ss) == true)
            {
                cout << ss << endl;
            }
        }
    }

    return 0;
}