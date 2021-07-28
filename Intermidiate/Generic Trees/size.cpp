#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    vector<Node *> children;
};

Node *construct(vector<int> arr)
{
    stack<Node *> st;
    Node *root = NULL;

    for (int i = 0; i < arr.size(); i++)
    {
        Node *node = new Node;
        node->data = arr[i];
        if (arr[i] == -1)
        {
            st.pop();
        }
        else
        {
            if (!st.empty())
            {
                Node *newNode = st.top();
                newNode->children.push_back(node);
            }
            else
            {
                root = node;
            }
            st.push(node);
        }
    }
    return root;
}

int sizeOfTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int size = 0;
    for (Node *child : root->children)
    {
        size += sizeOfTree(child);
    }
    return 1 + size;
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
    Node *root = construct(vec);
    cout << sizeOfTree(root);

    return 0;
}