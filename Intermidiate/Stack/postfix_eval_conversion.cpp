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
    stack<string> prefix;

    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp.at(i);
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            int vv2 = value.top();
            value.pop();
            int vv1 = value.top();
            value.pop();

            //value
            int val_v = operation(vv1, vv2, ch);
            value.push(val_v);

            //infix
            string iv2 = infix.top();
            infix.pop();
            string iv1 = infix.top();
            infix.pop();

            //postfix
            string val_i = "(" + iv1 + ch + iv2 + ")";
            infix.push(val_i);

            string pv2 = prefix.top();
            prefix.pop();
            string pv1 = prefix.top();
            prefix.pop();

            string val_p = ch + pv1 + pv2;
            prefix.push(val_p);
        }
        else
        {
            string temp_ch;
            temp_ch += ch;
            value.push(ch - '0');
            infix.push(temp_ch);
            prefix.push(temp_ch);
        }
    }
    cout << value.top() << endl;
    cout << infix.top() << endl;
    cout << prefix.top() << endl;

    return 0;
}
