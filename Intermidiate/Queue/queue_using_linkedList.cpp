#include<bits/stdc++.h>
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
Node* front = NULL;
Node* rear = NULL;

void QueueTraversal(){
    Node* ptr = front;
    while(ptr !=NULL){
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }
}


void enqueue(int val){
    Node* newNode = new Node(val);
    if(newNode == NULL){
        cout<<"Queue is full"<<endl;
    }
        newNode->data = val;
        if(front == NULL){
            front = rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
            cout<<rear->data<<" queued"<<endl;
        }
}

int dequeue(){
    Node* temp = front;
    int val = -1;
    if(front==NULL){
        cout<<"Queue is empty";
    }else{
        front = front->next;
        val = temp->data;
        delete temp;
    }

        return val;
}


int main(){
    enqueue(34);
    enqueue(34);
    enqueue(34);
    enqueue(34);
    cout<<dequeue()<<" dequeue"<<endl;

    QueueTraversal();
    return 0;
}
