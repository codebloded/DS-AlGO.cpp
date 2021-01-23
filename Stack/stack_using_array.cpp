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
    int peek(int pos);
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

int Stack::peek(int pos)
{
    int array_index = (top - pos + 1);
    if (array_index < 0)
    {
        cout << "Invalid index " << pos << " is not present in the stack" << endl;
        return -1;
    }
    return stack[array_index];
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
    s.push(13); //last in , first out
    cout << s.pop() << " is popped" << endl;

    cout << "Top element is " << s.stack[s.top] << endl;

    //Printing all values present in the stack using peek();
    for (int i = 1; i < 6; i++)
    {
        cout << s.peek(i) << " position is " << i << endl;
    }

    return 0;
}