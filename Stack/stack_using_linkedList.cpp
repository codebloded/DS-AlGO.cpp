#include<iostream>
using namespace std;

class StackNode{
    public:
        int data;
        StackNode* next;
};

StackNode* newNode(int x){
    StackNode* stackNode = new StackNode();
    stackNode->data = x;
    stackNode->next = NULL;
    return stackNode;

}

int isFull(StackNode* top){
    StackNode* n = new StackNode();
    if(n == NULL){
        return 1;
    }
    return 0;
}

int isEmpty(StackNode* top){
    if(top==NULL){
        return 1;
    }
    return 0;
}

void push(StackNode** top, int x){
    if(isFull(*top)){
        cout<<"Stack overflow"<<endl;
    }
    StackNode* temp = newNode(x);
    temp->data = x;
    temp->next = *top;
    *top = temp;
   
}

int pop(StackNode** top){
    if(isEmpty(*top)){
        cout<<"Stack UnderFlow"<<endl;
    }
    StackNode* temp = *top;
     *top= (*top)->next;
    int x = temp->data;
    delete temp;
    return x;
}

StackNode* linkedList_traversal(StackNode* top){
    StackNode* temp = top;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
    return top;
}




int main(){
    StackNode* top = NULL;
    push(&top,56);
    push(&top,3);
    push(&top,7);
    push(&top,23);
    push(&top,12); // last in , first out
    linkedList_traversal(top);
    int element = pop(&top);
    cout<<element<<" is popped"<<endl;
    linkedList_traversal(top);

    return 0;
}