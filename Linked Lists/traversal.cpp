#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
void display(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
//Driver Function
int main()
{
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    //allocating three node into heap memory
    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 34;
    head->next = second;

    second->data = 67;
    second->next = third;

    third->data = 89;
    third->next = NULL;

    display(head);

    return 0;
}