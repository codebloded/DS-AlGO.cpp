#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

void zigzag(Node *node)
{
    stack<Node *> ms; //main stack
    ms.push(node);
    int level = 1;

    stack<Node *> cs; // child stack
    while (ms.size() > 0)
    {
        Node *temp = ms.top();
        ms.pop();
        if (temp)
        {
            cout << temp->data << " ";

            //loops for adding child nodes into the child
            if (level % 2 == 1)
            {
                for (int i = 0; i < temp->children.size(); i++)
                {
                    Node *child = temp->children.at(i);
                    cs.push(child);
                }
            }
            else
            {
                for (int i = temp->children.size() - 1; i >= 0; i--)
                {
                    Node *child = temp->children.at(i);
                    cs.push(child);
                }
            }
        }
        if (ms.size() == 0)
        {
            swap(ms, cs);
            level++;
            cout << endl;
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
    zigzag(root);
    return 0;
}
