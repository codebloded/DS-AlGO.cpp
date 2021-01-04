//Problem: Simple searching an key element in a two dimessional array (matrix).
#include<iostream>
using namespace std;

int main(){
    int n ,m ,key=8;
    cin>>n>>m;
    int arr[n][m];
    //input

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m ; j++){
            if(arr[i][j] == key){
                cout<<"Element Found"<<endl;
            }
        }
    }
    return 0;
}