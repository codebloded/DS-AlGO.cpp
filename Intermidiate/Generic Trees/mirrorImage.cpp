#include <bits/stdc++.h>
#include "tree.h"

void mirror(Node *node)
{
    for (Node *child : node->children)
    {
        mirror(child);
    }
    reverse(node->children.begin(), node->children.end());
}

void display(Node *node)
{
    string str = to_string(node->data) + "->";
    for (Node *child : node->children)
    {
        str += to_string(child->data);
        str += ",";
    }
    str += ".";
    cout << str << endl;
    for (Node *child : node->children)
    {
        display(child);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    Node *root = construct(vec);
    mirror(root);
    display(root);

    return 0;
}