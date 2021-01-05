// Problem: Understanding character array and checking if the char array is palindrom or not;
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    char arr[n+1];
    cin>>arr;

    bool flag =0 ;
    for(int i=0; i<n; i++){
        if(arr[i] != arr[n-1-i]){
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout<<"The array is Palindrome";
    }else{
    cout<<"The array is not palindrome";
    }
    return 0;
}
