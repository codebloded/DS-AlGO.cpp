#include <bits/stdc++.h>
#include "Treeconstructor.h"
using namespace std;

static vector<Node *> path;
bool find(Node *node, int data)
{
    if (node->data == data)
    {
        path.push_back(node);
        return true;
    }
    if (node->left != nullptr)
    {
        bool fil = find(node->left, data);
        if (fil)
        {
            path.push_back(node);
            return true;
        };
    }
    if (node->right != nullptr)
    {
        bool fir = find(node->right, data);
        if (fir)
        {
            path.push_back(node);
            return true;
        };
    }
    return false;
}

void printKlevelDown(Node *node, int k, Node *blocker)
{
    if (node == nullptr || node == blocker)
    {
        return;
    }
    if (k == 0)
    {
        cout << node->data << endl;
    }
    printKlevelDown(node->left, k - 1, blocker);
    printKlevelDown(node->right, k - 1, blocker);
}

void printKlevelFar(Node *node, int k, int data)
{
    find(node, data);
    Node *blocker = nullptr;
    for (int i = 0; i < path.size(); i++)
    {
        Node *temp = path.at(i);
        printKlevelDown(temp, k - i, blocker);
        blocker = temp;
    }
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

    int data;
    cin >> data;
    int k;
    cin >> k;
    Node *root = construct(v);
    printKlevelFar(root, k, data);

    return 0;
}
