#include <bits/stdc++.h>
#include "tree.h"

bool find(Node *node, int data)
{
    if (node->data == data)
    {
        return true;
    }
    for (Node *child : node->children)
    {
        bool find_in_child = find(child, data);
        if (find_in_child)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int data;
    cin >> data;

    Node *root = construct(arr);
    bool x = find(root, data);
    if (x == true)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}