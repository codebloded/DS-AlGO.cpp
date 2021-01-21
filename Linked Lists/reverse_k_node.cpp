#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }
};

Node* reverse_KNode(Node* &head , int k){
    Node* prevNode = NULL;
    Node* currNode = head;
    Node* nextNode = head; 

    int count=0;
    while(currNode != NULL && count < k){
        nextNode = nextNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
        count++;
    }
    if(nextNode!= NULL){
        head->next = reverse_KNode(nextNode, k);
    }
    return prevNode;
}


void insertAtTail(Node* &head , int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next = newNode;
}

void display(Node* &head){
    Node* ptr = head;
    while(ptr != NULL){
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }
    cout<<"---NULL"<<endl;
}





int main(){
    Node* head = NULL;
    insertAtTail(head , 1);
    insertAtTail(head , 2);
    insertAtTail(head , 3);
    insertAtTail(head , 4);
    insertAtTail(head , 5);
    insertAtTail(head , 6);
    display(head);
    reverse_KNode(head , 2);
    display(head);

return 0;

}