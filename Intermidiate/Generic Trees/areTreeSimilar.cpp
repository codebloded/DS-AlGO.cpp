#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

bool areSimilar(Node *node1, Node *node2)
{
    if (node1->children.size() != node2->children.size())
    {
        return false;
    }
    for (int i = 0; i < node1->children.size(); i++)
    {
        Node *n1 = node1->children.at(i);
        Node *n2 = node2->children.at(i);
        if (areSimilar(n1, n2) == false)
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
    cout << boolalpha << areSimilar(root1, root2);

    return 0;
}