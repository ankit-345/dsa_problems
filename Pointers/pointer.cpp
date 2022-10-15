#include<bits/stdc++.h>
using namespace std;

int main(){

    // int a = 10;
    // int *ptr;
    // ptr = &a;
    // cout<<*ptr<<endl;
    // *ptr = *ptr +1;
    // cout<<*ptr;
    
    // POINTERS AND ARRAY
    int *ptr;
    int arr[]={10,20,30};
    ptr = arr;
    for(int i=0;i<3;i++)
    {
       cout<<*(arr+i)<<endl;   // we have done (arr+i) not (arr+4i) because it is points to index not to memory.
    }
   
    return 0;
}