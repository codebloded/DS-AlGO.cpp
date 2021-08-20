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
    display(root);

    return 0;
}
//50 25 12 n n 37 30 n n n 75 62 n 70 n n 87 n n