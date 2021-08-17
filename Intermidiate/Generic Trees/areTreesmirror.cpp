#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

bool areTreesMirror(Node *node1, Node *node2)
{
    if (node1->children.size() != node2->children.size())
    {
        return false;
    }

    for (int i = 0; i < node1->children.size(); i++)
    {
        Node *c1 = node1->children.at(i);
        Node *c2 = node2->children.at(node2->children.size() - 1 - i);
        if (areTreesMirror(c1, c2) == false)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int size;
    cin >> size;

    vector<int> arr1(size);
    for (int i = 0; i < size; i++)
    {
        cin >> arr1[i];
    }

    Node *root1 = construct(arr1);

    int size2;
    cin >> size2;
    vector<int> arr2(size);
    for (int i = 0; i < size2; i++)
    {
        cin >> arr2[i];
    }
    Node *root2 = construct(arr2);
    cout << boolalpha << areTreesMirror(root1, root2);

    return 0;
}