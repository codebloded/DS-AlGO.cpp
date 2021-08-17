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

static Node *predecessor;
static Node *successor;
static int state;
void predecessorAndSuccessor(Node *node, int data)
{
    if (state == 0)
    {
        if (node->data == data)
        {
            state = 1;
        }
        else
        {
            predecessor = node;
        }
    }
    else if (state == 1)
    {
        successor = node;
        state = 2;
    }

    for (Node *child : node->children)
    {
        predecessorAndSuccessor(child, data);
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
    Node *root = construct(vec);
    predecessor = NULL;
    successor = NULL;
    predecessorAndSuccessor(root, data);

    cout << "Predecessor = ";
    if (predecessor != NULL)
        cout << predecessor->data << endl;
    else
    {
        cout << "Not found" << endl;
    }
    cout << "Successor = ";
    if (successor != NULL)
        cout << successor->data;
    else
    {
        cout << "Not found" << endl;
    }
}
