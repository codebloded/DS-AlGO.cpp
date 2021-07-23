#include <bits/stdc++.h>
using namespace std;

int precedence(char ch)
{
    if (ch == '+')
    {
        return 1;
    }
    else if (ch == '-')
    {
        return 1;
    }
    else if (ch == '*')
    {
        return 2;
    }
    else
    {
        return 2;
    }
}

int operation(int v1, int v2, char ch)
{
    if (ch == '+')
    {
        return v1 + v2;
    }
    else if (ch == '-')
    {
        return v1 - v2;
    }
    else if (ch == '*')
    {
        return v1 * v2;
    }
    else
    {
        return v1 / v2;
    }
}

void infixEval(string exp)
{
    stack<int> oprnds;
    stack<char> optr;

    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp.at(i);
        if (ch == '(')
        {
            optr.push(ch);
        }
        else if (isdigit(ch))
        {
            oprnds.push(ch - '0');
        }
        else if (ch == ')')
        {
            while (optr.top() == '(')
            {

                char optor = optr.top();
                optr.pop();
                int v2 = oprnds.top();
                oprnds.pop();
                int v1 = oprnds.top();
                oprnds.pop();
                int opv = operation(v1, v2, optor);
                oprnds.push(opv);
            }
            optr.pop();
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            while (optr.size() > 0 && optr.top() != '(' && precedence(ch) <= precedence(optr.top()))
            {

                char optor = optr.top();
                optr.pop();
                int v2 = oprnds.top();
                oprnds.pop();
                int v1 = oprnds.top();
                oprnds.pop();
                int opv = operation(v1, v2, optor);
                oprnds.push(opv);
            }
            optr.push(ch);
        }
    }
    while (optr.size() != 0)
    {

        char optor = optr.top();
        optr.pop();
        int v2 = oprnds.top();
        oprnds.pop();
        int v1 = oprnds.top();
        oprnds.pop();
        int opv = operation(v1, v2, optor);
        oprnds.push(opv);
    }
    cout << oprnds.top();
}

int main()
{
    string exp;
    cin >> exp;
    infixEval(exp);
    return 0;
}
