#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

Node*  get_length(Node* head){
    Node* temp = new Node;
    temp = head;
    int counter = 0;
    while(temp !=NULL){
        counter++;
        temp = temp->next;
    }
    cout<<"The length of the linked list is :"<<counter;
    return head;

}

int main(){
      Node* head = NULL;
    Node* n2 = NULL;
    Node* n3 = NULL;
    Node* n4 = NULL;

    head = new Node();
    n2= new Node();
    n3= new Node();
    n4= new Node();

    head->data=34;
    head->next= n2;
    
    n2->data= 37;
    n2->next=n3;

    n3->data=56;
    n3->next = n4;

    n4->data=9;
    n4->next= NULL;

    head = get_length(head);
    
}