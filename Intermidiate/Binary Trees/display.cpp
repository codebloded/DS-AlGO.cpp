#include <bits/stdc++.h>
#include "Treeconstructor.h"
using namespace std;

void display(Node *node)
{
    if (node == nullptr)
    {
        return;
    }

    string str = "";
    str += node->left == nullptr ? "." : to_string(node->left->data);
    str += "<-" + to_string(node->data) + "->";
    str += node->left == nullptr ? "." : to_string(node->left->data);

    cout << str << endl;

    display(node->left);
    display(node->right);
}

int main()
{
    int n;
    cin >> n;
    int v[n];
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        if (x == "n")
        {
            v[i] = -1;
        }
        else
        {
            v[i] = stoi(x);
        }
    }
    Node *root = construct(v);
    display(root);

    return 0;
}
//50 25 12 n n 37 30 n n n 75 62 n 70 n n 87 n n