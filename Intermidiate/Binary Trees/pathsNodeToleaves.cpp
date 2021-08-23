#include <bits/stdc++.h>
#include "Treeconstructor.h"
using namespace std;

void pathNodeToleaf(Node *node, string s, int sum, int hi, int lo)
{
    if (node == nullptr)
    {
        return;
    }
    if (node->left == nullptr && node->right == nullptr)
    {
        sum += node->data;
        if (sum <= hi && sum >= lo)
        {
            cout << s + to_string(node->data) << endl;
        }
        return;
    }
    pathNodeToleaf(node->left, s + to_string(node->data) + " ", sum + node->data, hi, lo);
    pathNodeToleaf(node->right, s + to_string(node->data) + " ", sum + node->data, hi, lo);
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
    int lo, hi;
    cin >> lo >> hi;
    Node *root = construct(v);
    pathNodeToleaf(root, "", 0, hi, lo);

    return 0;
}