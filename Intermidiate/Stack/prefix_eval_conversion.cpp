#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    string exp;
    cin >> exp;
    stack<int> value;
    stack<string> infix;
    stack<string> postfix;

    for (int i = exp.length() - 1; i >= 0; i--)
    {
        char ch = exp.at(i);
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            //value
            int vv1 = value.top();
            value.pop();
            int vv2 = value.top();
            value.pop();

            int val_v = operation(vv1, vv2, ch);
            value.push(val_v);

            //infix
            string iv1 = infix.top();
            infix.pop();
            string iv2 = infix.top();
            infix.pop();

            string val_i = "(" + iv1 + ch + iv2 + ")";
            infix.push(val_i);

            //postfix
            string pv1 = postfix.top();
            postfix.pop();
            string pv2 = postfix.top();
            postfix.pop();

            string val_p = pv1 + pv2 + ch;
            postfix.push(val_p);
        }
        else
        {
            string temp_ch;
            temp_ch += ch;
            value.push(ch - '0');
            infix.push(temp_ch);
            postfix.push(temp_ch);
        }
    }
    cout << value.top() << endl;
    cout << infix.top() << endl;
    cout << postfix.top() << endl;

    return 0;
}
