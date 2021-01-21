//Impelementation of doubly linked list with insertion and deletion with different cases;
#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* prev;

    Node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void insertAtHead(Node* &head , int val){
    Node* n = new Node(val);
    n->next=head;
    if(head != NULL){
        head->prev= n;
    }

    head = n;

}

void insertAtTail(Node* &head , int val){

    if(head==NULL){
        insertAtHead(head , val);
        return;
    }

    Node* n = new Node(val);
    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next=n;
    n->prev=temp;
}

void display(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    };
    cout<<endl;
}

void deleteHead(Node* &head){
    Node* temp = head;
    head = head->next;
    head->prev =NULL;  // Beacause the previous of the first node is alaways NULL
     delete temp;

}
void deleteInBetween(Node* &head , int index){
    Node* temp = head;
    int count =1;
    while(temp !=NULL && count != index){
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if(temp->next != NULL){ 
      temp->next->prev = temp->prev;
    }
    delete temp;

}


int main(){
    Node* head = NULL;
    insertAtTail(head , 45);
    insertAtTail(head , 4);
    insertAtTail(head , 5);
    insertAtTail(head , 455);
    insertAtTail(head , 43);
    insertAtTail(head , 41);
    // display(head);
    // insertAtHead(head, 66);


    deleteInBetween(head, 2);
    deleteInBetween(head, 4);
    deleteHead(head);
    display(head);
    
    return 0;
}