#include <bits/stdc++.h>
#include "Treeconstructor.h"
using namespace std;

void printKlevelDown(Node *node, int k)
{
    if (node == nullptr)
    {
        return;
    }
    if (k == 0)
    {
        cout << node->data << endl;
    }
    printKlevelDown(node->left, k - 1);
    printKlevelDown(node->right, k - 1);
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

    int k;
    cin >> k;
    Node *root = construct(v);
    printKlevelDown(root, k);
    return 0;
}