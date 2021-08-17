#include <bits/stdc++.h>
#include "tree.h";
using namespace std;

static int ceilx;
static int floorx;
void ceilandfloor(Node *node, int data)
{
    if (node->data > data)
    {
        if (ceilx > node->data)
        {
            ceilx = node->data;
        }
    }

    if (node->data < data)
    {
        if (floorx < node->data)
        {
            floorx = node->data;
        }
    }

    for (Node *child : node->children)
    {
        ceilandfloor(node, data);
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
    int data;
    cin >> data;

    ceilx = INT_MAX;
    floorx = INT_MIN;
    Node *root = construct(vec);
    ceilandfloor(root, data);
    cout << "CEIL " << ceilx << endl;
    cout << "FLOOR " << floorx << endl;
}
