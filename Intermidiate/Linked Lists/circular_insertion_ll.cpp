#include<iostream>
using namespace std;


class Node{
    public:
        int data;
        Node* next;
};

Node* circular_traverse(Node* head){
    Node* ptr = head;
    do{
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }while(ptr != head);
    return head;
}

Node* insertAt_first_node(Node* head, int new_data){
    Node* ptr = new Node;
    ptr->data=new_data;

    Node* temp = head->next;
    while(temp->next != head){
        temp = temp->next;
    }
    //Now temp is at head 
    temp->next = ptr;
    ptr->next = head;
    head = ptr;
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
    n4->next= head;


    
    circular_traverse(head);
    head = insertAt_first_node(head, 566);
    head = insertAt_first_node(head, 56);
    cout<<"after insering the node at the fisrt"<<endl;

    circular_traverse(head);



    return 0;
}