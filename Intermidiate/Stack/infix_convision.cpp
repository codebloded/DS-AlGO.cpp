#include <bits/stdc++.h>
using namespace std;

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

void conversion(string exp)
{
    //Three stacks 1. prefix 2.operators 3. postfix
    stack<string> postfix;
    stack<string> prefix;
    stack<char> operators;

    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp.at(i);
        if (ch == '(')
        {
            operators.push(ch);
        }
        else if ((ch >= '0' && ch <= '9') ||
                 (ch >= 'a' && ch <= 'z') ||
                 (ch >= 'A' && ch <= 'Z'))
        {
            string temp_ch;
            temp_ch += ch;
            postfix.push(temp_ch);
            prefix.push(temp_ch);
        }
        else if (ch == ')')
        {
            while (operators.top() != '(')
            {
                char op = operators.top();
                operators.pop();

                string post2 = postfix.top();
                postfix.pop();
                string post1 = postfix.top();
                postfix.pop();

                string postv = op + post1 + post2;
                postfix.push(postv);

                string pre2 = prefix.top();
                prefix.pop();
                string pre1 = prefix.top();
                prefix.pop();

                string prev = pre1 + pre2 + op;
                prefix.push(prev);
            }
            operators.pop();
        }
        else
        {
            while (operators.size() > 0 && operators.top() != '(' && precedence(ch) <= precedence(operators.top()))
            {
                char op = operators.top();
                operators.pop();

                string post2 = postfix.top();
                postfix.pop();
                string post1 = postfix.top();
                postfix.pop();

                string postv = op + post1 + post2;
                postfix.push(postv);

                string pre2 = prefix.top();
                prefix.pop();
                string pre1 = prefix.top();
                prefix.pop();

                string prev = pre1 + pre2 + op;
                prefix.push(prev);
            }
            operators.push(ch);
        }
    }
    while (operators.size() != 0)
    {
        char op = operators.top();
        operators.pop();

        string post2 = postfix.top();
        postfix.pop();
        string post1 = postfix.top();
        postfix.pop();

        string postv = op + post1 + post2;
        postfix.push(postv);

        string pre2 = prefix.top();
        prefix.pop();
        string pre1 = prefix.top();
        prefix.pop();

        string prev = pre1 + pre2 + op;
        prefix.push(prev);
    }
    cout << prefix.top() << endl;
    cout << postfix.top() << endl;
    prefix.pop();
    postfix.pop();
}

int main()
{
    string exp;
    getline(cin, exp);
    conversion(exp);

    return 0;
}
