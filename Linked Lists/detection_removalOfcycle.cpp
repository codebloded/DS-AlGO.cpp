// Problem: FLOYD'S ALGORITHUM for detection and removal of cycle in an linked list also known as (Hare and Trotoise algorithum)
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display(Node *&head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "-NULL" << endl;
}

void makeCycle(Node *&head, int pos)
{
    int count = 0;
    Node *startCycle;
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            startCycle = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startCycle;
}

bool detect_cycle(Node *&head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

void remove_cycle(Node *&head)
{
    Node *slow = head;
    Node *fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}

int main()
{
    Node *head = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 9; i++)
    {
        insertAtTail(head, arr[i]);
    }
    display(head);
//Make cylce
    makeCycle(head, 4);
//removing the cycle
    remove_cycle(head);
//detection of cycle
    cout << endl
         << detect_cycle(head);
    display(head);
    return 0;
}