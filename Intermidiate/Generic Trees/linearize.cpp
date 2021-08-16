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
Node *getTail(Node *node)
{
    while (node->children.size() == 1)
    {
        node = node->children.at(0);
    }
    return node;
}

void linearize(Node *node)
{
    for (Node *child : node->children)
    {
        linearize(child);
    }
    while (node->children.size() > 1)
    {
        Node *temp_head = node->children.at(node->children.size() - 1);
        node->children.erase(node->children.begin() + node->children.size() - 1);
        Node *temp_tail = getTail(node->children.at(node->children.size() - 1));
        temp_tail->children.push_back(temp_head);
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

    Node *root = construct(arr);
    linearize(root);
    display(root);

    return 0;
}