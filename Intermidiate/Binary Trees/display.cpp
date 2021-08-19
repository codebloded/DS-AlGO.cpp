#include <bits/stdc++.h>
#include "Treeconstructor.h"
using namespace std;

void display(Node *node)
{
    if (node == nullptr)
    {
        return;
    }

    string str = "";
    str += node->left == nullptr ? "." : to_string(node->left->data);
    str += "<-" + to_string(node->data) + "->";
    str += node->left == nullptr ? "." : to_string(node->left->data);

    cout << str << endl;

    display(node->left);
    display(node->right);
}

int main()
{
    int size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        cin >> arr.at(i);
    }
    Node *root = construct(arr);
    display(root);

    return 0;
}
