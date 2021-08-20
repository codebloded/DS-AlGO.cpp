#include <bits/stdc++.h>
#include "Treeconstructor.h"
using namespace std;

void traversals(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    cout << node->data << "in preorder" << endl;
    traversals(node->left);

    cout << node->data << "in inorder" << endl;
    traversals(node->right);
    cout << node->data << " in postorder" << endl;
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
    traversals(root);
}