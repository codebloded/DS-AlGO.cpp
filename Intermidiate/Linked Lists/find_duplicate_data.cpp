#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    Node(int val){
        data = val;
        next =NULL;
    }
};

void insertAtTail(Node* &head, int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
void display(Node* &head){
    Node* ptr = head;
    while(ptr != NULL){
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }
    cout<<"NULL"<<endl;
}

//Function for finding duplicate data in Linked list;
int find_duplicate(Node* &head){
    Node* temp = head->next;
    int n = head->data;
    while( temp!=NULL){
        if(head->data == temp->data){
            n = temp->data;
        cout<<temp->data;
        return n;
        }
        temp = temp->next;
    }
    if(head->data == n){

    return n;
    }
    
}

int main(){
    Node* head = NULL;
    insertAtTail(head, 21);
    insertAtTail(head, 35);
    insertAtTail(head, 1);
    insertAtTail(head, 3);
    insertAtTail(head, 24);
    insertAtTail(head, 1);

    cout<<find_duplicate(head)<<endl;
    display(head);
}