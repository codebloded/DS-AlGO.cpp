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
            if (st.size() > 0)
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

void traverse(Node *node)
{
    cout << "Node Pre " << node->data << endl;
    for (Node *child : node->children)
    {
        cout << "Edge Pre " << node->data << "--" << child->data << endl;
        traverse(child);
        cout << "Edge Post " << node->data << "--" << child->data << endl;
    }
    cout << "Node Post " << node->data << endl;
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
    traverse(root);
    return 0;
}