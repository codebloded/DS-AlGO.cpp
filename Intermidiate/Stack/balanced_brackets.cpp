#include <bits/stdc++.h>
using namespace std;

bool handleC(stack<char> &s, char ch)
{
    if (s.empty())
    {
        return 0;
    }
    else if (s.top() != ch)
    {
        return 0;
    }
    else
    {
        s.pop();
        return 1;
    }
    return 1;
}

void parenthesis_matching(string expr)
{
    //Implementing stack using stl stacks
    stack<char> s;

    for (int i = 0; i < expr.length(); i++)
    {

        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '{')
        {
            s.push(expr[i]);
        }

        else if (expr[i] == ')')
        {
            bool val = handleC(s, '(');
            if (val == 0)
            {
                cout << "false";
                return;
            }
        }
        else if (expr[i] == '}')
        {
            bool val = handleC(s, '{');
            if (val == 0)
            {
                cout << "false";
                return;
            }
        }
        else if (expr[i] == ']')
        {
            bool val = handleC(s, '[');
            if (val == 0)
            {
                cout << "false";
                return;
            }
        }
        else
        {
        }
    }
    if (s.size() == 0)
    {
        cout << "false";
    }
    else
    {
        cout << "true";
    }
}

int main()
{
    string expr;
    getline(cin, expr);
    parenthesis_matching(expr);

    return 0;
}