#include <bits/stdc++.h>
using namespace std;

int match(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}

bool parenthesis_matching(string expr)
{
    //Implementing stack using stl stacks
    stack<char> s;
    char popped_ch;

    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '{')
        {
            s.push(expr[i]);
            continue;
        }

        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']')
        {
            //checking for stack is empty or not!

            if (s.empty())
            {
                return 0;
            }
            popped_ch = s.top();
            if (!s.empty())
            {
                s.pop();
            }
            if (!match(popped_ch, expr[i]))
            {
                return 0;
            }
        }
    }
    return (s.empty());
}

int main()
{
    string expr = "{())}";
    if (parenthesis_matching(expr))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}