#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

void levelorderLinewise(Node *node)
{
    queue<Node *> q;
    q.push(node);
    q.push(NULL);

    while (q.size() > 0)
    {
        node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout << node->data << " ";
            for (Node *child : node->children)
            {
                q.push(child);
            }
        }
        else
        {
            if (q.size() > 0)
            {
                q.push(NULL);
                cout << endl;
            }
        }
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

    Node *root = construct(arr);
    levelorderLinewise(root);

    return 0;
}
