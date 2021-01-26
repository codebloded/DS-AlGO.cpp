#include<bits/stdc++.h>
using namespace std;

class Queue{
    public: 
        int front, rear;
        int *arr;
        int capacity;
    Queue(int val){
        front = rear = 0;
        arr = new int;
    }
    ~Queue(){
        delete[] arr;
    }

    void enqueue(int x){
        if((rear+1)%capacity == front){ //condidtion for isFullQueue()
            cout<<"Queue Overflow"<<endl;
        }
        else{
            rear = (rear+1)%capacity; //This is circular increment 
            arr[rear] = x;     
            cout<<x<<" is queued"<<endl;       
        }
        return;
    }

    int dequeue(){
        int item;
        if(rear == front){
            cout<<"Queue is empty"<<endl;
        }
        else{
            front = (front+1)%capacity;
            item = arr[front];
        }
        return item;
    }
    void displayQueue(){
        if(rear == front){
            cout<<"Queue is empty"<<endl;
        }
        for(int i=front+1; i<rear+1 ; i++){
            cout<<arr[i]<<" ";
        }
        
    }
};





int main(){
    Queue queue(4);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    cout<<queue.dequeue()<<" is dequeued"<<endl;
    cout<<queue.dequeue()<<" is dequeued"<<endl;
    cout<<queue.dequeue()<<" is dequeued"<<endl;
    cout<<queue.dequeue()<<" is dequeued"<<endl;
    cout<<queue.dequeue()<<" is dequeued"<<endl;
    queue.enqueue(67);
  
    queue.displayQueue();
 
    
    

    return 0;
}