#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    cin.ignore(); // because we are using getline and to remove the buffer

    char arr[n+1];
    cin.getline(arr, n);
    cin.ignore();

    int i=0;
    int curLen = 0, maxLen = 0;
    int st=0;       // analogous of curLen(gives starting position of longest word)
    int maxst =0;   // analogous of maxLen
    while(1){

        if(arr[i] == ' ' || arr[i] == '\0'){
            if( curLen > maxLen){
               maxLen = curLen;
               maxst = st;
            }
            curLen = 0;
            st = i+1;
        } 
        else
          curLen++;
        if(arr[i] == '\0')
        {
            break;
        }
        i++;
    }
    cout<<maxLen<<endl;
    for(int i=0; i<maxLen; i++)
        cout<<arr[i+maxst];
    return 0;
}