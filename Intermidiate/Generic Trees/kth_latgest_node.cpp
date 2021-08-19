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

static int ceilx;
static int floorx;
void ceilandfloor(Node *node, int data)
{
    if (node->data > data)
    {
        if (ceilx > node->data)
        {
            ceilx = node->data;
        }
    }

    if (node->data < data)
    {
        if (floorx < node->data)
        {
            floorx = node->data;
        }
    }

    for (Node *child : node->children)
    {
        ceilandfloor(node, data);
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
    for(int i=0; i<data; i++){
        int factor = INT_MAX;
        floorx = INT_MIN;
        ceilandfloor(root, factor);
        floorx=factor;
        floorx = INT_MIN;
    }
   
    
}
