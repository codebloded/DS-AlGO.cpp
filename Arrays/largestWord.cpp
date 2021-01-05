// Problem : Find the largest word in a sentence
#include<iostream>
using namespace std;

int main(){
    int n ;
    cin>>n;
    cin.ignore();
    char line[n+1];
    cin.getline(line,n); 
    cin.ignore();

    int i=0;
    int currentLen=0;
    int maxLength=0;

    while(1){
        
        if(line[i]==' ' || line[i] == '\0'){
            if(currentLen > maxLength){
                maxLength = currentLen;
            }
            currentLen=0;
        }else{
            currentLen++;
        }


        if(line[i] == '\0'){
            break;
        }
        i++;
    }

    cout<<maxLength;
    return 0;

}