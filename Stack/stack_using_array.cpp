#include <iostream>
#include <stack>
using namespace std;

#define MAX 100

class Stack
{
public:
    int top;
    int stack[MAX];

    Stack()
    {
        top = -1;
    }
    bool push(int val);
    int pop();
    bool isEmpty();
};

bool Stack::isEmpty()
{
    return (top < 0);
}

bool Stack::push(int val)
{
    if (top >= (MAX - 1))
    {
        cout << "Stack overFlow" << endl;
        return false;
    }
    else
    {

        top++;
        stack[top] = val;
        cout << val << " is pushed into stack" << endl;
        return true;
    }
}

int Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack underflow" << endl;
        return 0;
    }
    else
    {

        int x;
        x = stack[top--];
        return x;
    }
}

int main()
{

    class Stack s;
    s.push(56);
    s.push(32);
    s.push(34);
    s.push(67);
    s.push(78);
    s.push(13);
    cout << s.pop() << " is popped" << endl;

    cout << "Top element is " << s.stack[s.top];
    return 0;
}