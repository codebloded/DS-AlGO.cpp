#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    
    Node(int val){
        data = val;
        next = NULL;
    }
};



int length(Node* head){
    Node* ptr = head;
    int count=0;
    while(ptr != NULL){
        ptr = ptr->next;
        count++;
    }
    return count;
}

Node* Kappend_node(Node* head , int k){
    Node* newTail;
    Node* newHead;
    Node* tail = head;
    int count=1;

    int l = length(head);
    k = k%l;

    while(tail->next != NULL){
        if(count == l-k){
            newTail = tail;
        }
        if(count == l-k+1){
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }
        newTail->next = NULL;
        tail->next = head;
        return newHead;
}


void insertAtTail(Node* &head , int val){
    Node* newNode = new Node(val);
    if(head ==NULL){
        head = newNode;
        return;
    }
    Node* temp=head;
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




int main(){
    Node* head = NULL;
    int arr[] = {1,2,3,4,5,6};
    for(int i=0; i<6; i++){
        insertAtTail(head, arr[i]);
    }
    display(head);
    Node* newHead = Kappend_node(head,3);
    display(newHead);
    return 0;
}