#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

void removeleaves(Node *node)
{
    for (int i = node->children.size() - 1; i >= 0; i--)
    {
        Node *child = node->children.at(i);
        if (child->children.size() == 0)
        {
            node->children.erase(node->children.begin() + i);
        }

        for (Node *child : node->children)
        {
            removeleaves(child);
        }
    }
}

int main()
{
    vector<int> arr;
    for (int i = 0; i < arr.size(); i++)
    {
        arr.push_back(i);
    }
    Node *root = construct(arr);
    removeleaves(root);
    return 0;
}