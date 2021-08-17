#include <bits/stdc++.h>
#include "tree.h";
using namespace std;

void nodeToRootPath(Node *node, int data, vector<int> &path)
{
    if (node->data == data)
    {
        path.push_back(node->data);
        return;
    }

    for (Node *child : node->children)
    {
        nodeToRootPath(child, data, path);
        if (path.size() > 0)
        {
            path.push_back(node->data);
            return;
        }
    }
}

int LCA(Node *node, int data1, int data2)
{
    vector<int> path1, path2;
    nodeToRootPath(node, data1, path1);
    nodeToRootPath(node, data2, path2);
    int i = path1.size() - 1;
    int j = path2.size() - 1;
    while (i >= 0 && j >= 0 && path1.at(i) == path2.at(j))
    {
        i--;
        j--;
    }
    i++;
    j++;
    return (i + j);
}

void display(Node *node)
{
    string str = to_string(node->data) + " -> ";
    for (Node *child : node->children)
    {
        str += to_string(child->data);
        str += ", ";
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
    int size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int data1, data2;
    cin >> data1;
    cin >> data2;

    Node *root = construct(arr);
    vector<int> path;
    cout << LCA(root, data1, data2);

    return 0;
}