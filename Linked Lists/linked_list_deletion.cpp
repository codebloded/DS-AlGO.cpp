#include<iostream>
using namespace std;

//Initializing the linked list
class Node{
    public:
        int data;
        Node* next;
};

void display(Node* ptr){
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

Node* delete_first_node(Node* head){
    Node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

Node* delete_between_node(Node* head, int index){
    Node* ptr = head;
    int i=0;
    while(i!=index-1){
        ptr = ptr->next;
        i++;
    }
    Node* q = ptr->next;
    ptr->next = q->next;
    free(q);

    return head;
}
Node* delete_last_node(Node* head){
    Node* ptr = head;
    Node* q = head->next;
    while(q->next!= NULL){
        ptr = ptr->next;
        q= q->next;
    }
    ptr->next=NULL;
    free(q);
    return head;
}
Node* delete_at_value(Node* head , int value){
    Node* ptr = head;
    Node* q = head->next;
    while(q->data !=value && q->next != NULL){
        ptr=ptr->next;
        q=q->next;
    }
    if(q->data==value){
        ptr->next = q->next;
        free(q);
    }
    return head;
}


int main(){
    Node* head = NULL;
    Node* sec = NULL;
    Node* third = NULL;
    Node* four = NULL;
    
    //allocating these nodes into the heap memory dynamically;
    head = new Node();   
    sec = new Node();   
    third = new Node();   
    four = new Node();   

    head->data=45;
    head->next= sec;
    
    sec->data = 78;
    sec->next= third;

    third->data=88;
    third->next=four;

    four->data= 12;
    four->next = NULL;

    display(head);
    // head = delete_first_node(head);
    // head = delete_between_node(head,2);
    // delete_last_node(head);
    head = delete_at_value(head);
    display(head);
 


    return 0;
}