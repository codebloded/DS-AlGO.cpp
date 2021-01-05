#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

// Function to Insert a node at beginning
Node* insertAt_front(Node* head, int new_data){
    //new Node to be inserted
    Node* temp = new Node();
    temp->next = head;
    temp->data = new_data;
    return temp;
}

//Function to insert a node in between the linked list
Node* insertAt_index(Node* head , int new_data , int index){
    Node* temp = new Node();
    Node* p = head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    temp->data= new_data;
    temp->next = p->next;
    p->next = temp;
    return head;

}

//Function to insert the node at the end of the linkedlist
Node* insertAt_end(Node* head , int new_data){
    Node* temp = new Node();
    temp->data= new_data;
    Node* p = head;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = temp;
    temp->next=NULL;
    return head;
}

//Function to insert the node after a given node in a linkedlist
Node* insert_after_node(Node* head , Node* prevNode , int new_data){
    Node* temp = new Node();
    temp->data= new_data;

     temp->next=prevNode->next ;
    prevNode->next =temp;
    return head;
}

void display(Node* temp){
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    Node* head = NULL;
    Node* sec = NULL;
    Node* third = NULL;
    Node* four = NULL;
    
    //allocating four node into heap memory
    head = new Node();
    sec = new Node();
    third = new Node();
    four = new Node();

    head->data = 45;
    head->next=sec;

    sec->data=67;
    sec->next=third;
    third->data=90;
    third->next=four;
    four->data=32;
    four->next=NULL; 

    // insertAt_front(head , 78);
    // head = insertAt_index(head, 79, 1);
    // head = insertAt_end(head, 1);
    head = insert_after_node(head , sec, 800);
    display(head);


}