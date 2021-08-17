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

static int size;
static int mini;
static int maxi;
static int height;
void multisolver(Node *node, int depth)
{
    size = size + 1;
    height = max(depth, height);
    maxi = max(maxi, node->data);
    mini = min(mini, node->data);
    for (Node *child : node->children)
    {
        multisolver(child, depth + 1);
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
    Node *root = construct(vec);

    size = 0;
    mini = INT_MAX;
    maxi = INT_MIN;
    height = 0;
    multisolver(root, 0);

    cout << "Size " << size << endl;
    cout << "Max " << maxi << endl;
    cout << "Min " << mini << endl;
    cout << "Height " << height << endl;

    return 0;
}