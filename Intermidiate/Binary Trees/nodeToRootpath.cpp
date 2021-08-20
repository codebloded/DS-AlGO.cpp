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

Node *construct(int *arr)
{
    Node *root = new Node(arr[0]);
    pair<Node *, int> p = {root, 1};

    stack<pair<Node *, int>> st;
    st.push(p);

    int idx = 1;
    while (!st.empty())
    {
        if (st.top().second == 1)
        {
            st.top().second++;
            if (arr[idx] != -1)
            {
                st.top().first->left = new Node(arr[idx]);
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
            if (arr[idx] != -1)
            {
                st.top().first->right = new Node(arr[idx]);
                pair<Node *, int> rp = {st.top().first->right, 1};
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
//Write your function here !
static vector<int> path;
bool find(Node *node, int data)
{
    if (node->data == data)
    {
        path.push_back(node->data);
        return true;
    }
    if (node->left != nullptr)
    {
        bool fil = find(node->left, data);
        if (fil)
        {
            path.push_back(node->data);
            return true;
        };
    }
    if (node->right != nullptr)
    {
        bool fir = find(node->right, data);
        if (fir)
        {
            path.push_back(node->data);
            return true;
        };
    }
    return false;
}

vector<int> nodeToRootPath(Node *node, int data, vector<int> path)
{
    if (node->data == data)
    {
        path.push_back(node->data);
        return path;
    }

    vector<int> leftpath = nodeToRootPath(node->left, data, path);
    if (leftpath.size() > 0)
    {
        leftpath.push_back(node->data);
        return leftpath;
    }

    vector<int> rightpath = nodeToRootPath(node->right, data, path);
    if (rightpath.size() > 0)
    {
        rightpath.push_back(node->data);
        return rightpath;
    }

    return path;
}

int main()
{

    int n;
    cin >> n;
    int v[n];
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        if (x == "n")
        {
            v[i] = -1;
        }
        else
        {
            v[i] = stoi(x);
        }
    }
    int data;
    cin >> data;
    Node *root = construct(v);
    cout << boolalpha << find(root, data) << endl;
    cout << '[';
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