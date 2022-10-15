#include <iostream>
using namespace std;

void primeSieve(int n){

    int prime[100]={0};

    for(int i=2; i<n; i++){
        if(prime[i]==0)    // 0 means unmarked
        for(int j=i*i; j<=n; j+=i){   // This loop is for marking the non-prime words
            prime[j]=1;    // 1 means marked
        }
    }

    for(int i=2; i<n; i++){
        if(prime[i]==0){
            cout<<i<<" ";
        }
    }cout<<endl;
}


int main(){
     int n;
     cin>>n;
    
    primeSieve(n);
    return 0;
}