#include <bits/stdc++.h>
#include "tree.h"

void levelOrder(Node *node)
{
    queue<Node *> que;
    if (node == NULL)
    {
        return;
    }
    que.push(node);
    while (que.size() > 0)
    {
        //remove
        node = que.front();
        que.pop();
        //print
        cout << node->data << endl;
        //add

        for (Node *child : node->children)
        {
            que.push(child);
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
    levelOrder(root);
    return 0;
}