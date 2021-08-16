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

    int data;
    cin >> data;

    Node *root = construct(arr);
    vector<int> path;
    nodeToRootPath(root, data, path);
    cout << "[";
    if (path.size() != 0)
    {

        for (int i = 0; i < path.size() - 1; i++)
        {
            cout << path.at(i) << ", ";
        }
        cout << path.at(path.size() - 1) << "]";
    }
    else
    {
        cout << "]";
    }

    return 0;
}