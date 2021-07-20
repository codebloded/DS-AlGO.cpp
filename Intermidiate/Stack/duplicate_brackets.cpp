#include <bits/stdc++.h>
using namespace std;

bool findDuplicate(stack<char> &Stack, string exp)
{
    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp.at(i);
        if (ch == ')')
        {
            if (Stack.top() == '(')
            {
                return true;
            }
            else
            {
                while (Stack.top() != '(')
                {
                    Stack.pop();
                }
                Stack.pop();
            }
        }
        else
        {
            Stack.push(ch);
        }
    }
    return false;
}
int main()
{
    stack<char> Stack;
    string exp;
    getline(cin, exp);
    if (findDuplicate(Stack, exp))
    {
        cout << "ture";
    }
    else
    {
        cout << "false";
    }
}