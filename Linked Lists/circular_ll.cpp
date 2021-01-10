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

    head = circular_traverse(head);


    return 0;
}