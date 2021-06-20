#include<bits/stdc++.h>
using namespace std;

class Queue{
    public: 
        int front , rear;
        int *arr;
        int capacity;
    Queue(int val){
        front = rear =-1;
        capacity = val;
        arr = new int;
    }
    ~Queue(){
        delete[] arr;
    }

    void enqueue(int x){
        if(rear == capacity){
            cout<<"queue overflow";
        }
        else{
            rear++;
            arr[rear] = x;
            cout<<x<<" is queued"<<endl;
        }
        return;
    }
    void dequeue(){
        int item ;
        if(rear == front){
            cout<<"Queue is Empty";
        }
        else{
            front++;
            item = arr[front];
        }
        cout<<item<<" is dequeued"<<endl;
        return ;
    }
    void displayQueue(){
        if(rear == front){
            cout<<"Queue is empty"<<endl;
        }
        for(int i=front+1; i<rear+1; i++){
            cout<<arr[i]<<" ";
        }
        return;
    }

};



int main(){
    Queue q(40);
    q.enqueue(45);
    q.enqueue(9);
    q.enqueue(1);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(67);
    q.displayQueue();



    return 0;
}