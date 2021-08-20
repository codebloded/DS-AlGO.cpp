#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node *construct(vector<int> &arr)
{
    Node *root = new Node(arr.at(0));
    pair<Node *, int> p = {root, 1};

    stack<pair<Node *, int>> st;
    st.push(p);

    int idx = 1;
    while (!st.empty())
    {
        if (st.top().second == 1)
        {
            st.top().second++;
            if (arr.at(idx) != -1)
            {
                st.top().first->left = new Node(arr.at(idx));
                pair<Node *, int> lp = {st.top().first->left, 1};
                st.push(lp);
            }
            else
            {
                st.top().first->left = nullptr;
            }
            idx++;
        }
        else if (st.top().second == 2)
        {
            st.top().second++;
            if (arr.at(idx) != -1)
            {
                st.top().first->right = new Node(arr.at(idx));
                pair<Node *, int> rp = {st.top().first->right, 2};
                st.push(rp);
            }
            else
            {
                st.top().first->right = nullptr;
            }
            idx++;
        }
        else
        {
            st.pop();
        }
    }
    return root;
}

int max_node(Node *node)
{
    if (node == nullptr)
    {
        return INT_MIN;
    }

    int lm = max_node(node->left);
    int rm = max_node(node->right);

    int _max = max(node->data, max(lm, rm));
    return _max;
}

int tree_size(Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    int ls = tree_size(node->left);
    int rs = tree_size(node->right);

    int ts = ls + rs + 1;
    return ts;
}

int sum(Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    int lsm = sum(node->left);
    int rsm = sum(node->right);
    int tsm = lsm + rsm + node->data;
    return tsm;
}

int height(Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    int h = INT_MIN;
    int lh = height(node->left);
    int rh = height(node->right);
    return max(lh, rh) + 1;
}

int main()
{
    int size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        string x;
        cin >> x;

        if (x == "n")
        {
            arr.at(i) = -1;
        }
        else
        {
            arr.at(i) = stoi(x);
        }
    }
    Node *root = construct(arr);
    cout << tree_size(root) << endl;
    cout << sum(root) << endl;
    cout << max_node(root) << endl;
    cout << height(root) << endl;
    return 0;
}