//Problem : Find the transpose of a matrix 
#include<iostream>
using namespace std;

int main(){
    int arr[3][3] = { {1,4,5} , {6,3,5} , {8,1,2} };

    //transpose
    for(int i=0; i<3; i++){
        for(int j=0; j<3 ; j++){
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }

    return 0;

}