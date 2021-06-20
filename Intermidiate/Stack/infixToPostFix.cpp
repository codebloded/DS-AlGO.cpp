#include<bits/stdc++.h>
using namespace std;

int isOperator(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/' ){
        return 1;
    }
    return 0;
}

int precedence(char c){
    if(c=='/' || c=='*'){
        return 3;
    }
   
    else if(c=='+' || c=='-'){
        return 2;
    }
       
   return 0;
   
}

void infix_to_PostFix(string infix){
    stack<char> s;
    s.push('\0');
    string postfix;
    char popped_ch;
    int i=0; 
    int j=0;
    for(int i=0; i<infix.length(); i++){
        if((infix[i] >= 'a' && infix[i] <= 'z') ||  
           (infix[i] >= 'A' && infix[i] <= 'Z')) {
            postfix += infix[i];
        }
        else if(infix[i] == '('){
            s.push('(');

        }
        else if(infix[i] ==')'){
            while(s.top() !='\0' && s.top() =='('){
                popped_ch = s.top();
                s.pop();
                postfix += popped_ch;
            }
            if(s.top() == '('){
                popped_ch = s.top();
                s.pop();
            }
        }
        else{
            while(s.top() !='\0' && precedence(infix[i]) <= precedence(s.top())){
                    popped_ch = s.top();
                    s.pop();
                    postfix += popped_ch;
            }
            s.push(infix[i]);
        }

    }
    while(s.top() !='\0'){
        popped_ch = s.top();
        s.pop();
        postfix += popped_ch;
    }
    cout<<postfix<<endl;
}




int main(){
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    infix_to_PostFix(infix);
    return 0;
}