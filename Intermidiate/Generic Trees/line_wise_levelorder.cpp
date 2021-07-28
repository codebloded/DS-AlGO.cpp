#include <iostream>
#include "tree.h"

void lineWise(Node *node)
{
    queue<Node *> mq;
    mq.push(node);
    int level = 1;

    while (mq.size() > 0)
    {
        node = mq.front();
        level--;
        mq.pop();
        cout << node->data << " ";
        for (Node *child : node->children)
        {
            mq.push(child);
        }
        if (level == 0)
        {
            cout << endl;
            level = mq.size();
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
    lineWise(root);
    return 0;
}