#include <iostream>
using namespace std;

void primefactor(int n){

    int spf[100]={0};    // spf means smallest prime factor

    for(int i=2;i<=n;i++){
        spf[i]=i;      // it is because spf of 2 is 2 and so of 3.
    }

    for(int i=2;i<=n;i++){
        if(spf[i]==i){    // it checks whether it is unmarked
            for(int j=i*i; j<=n; j+=i){
                if(spf[j]==j){    // it means that is if spf of 20 is 20 which is not true , so we make it equal to i(2) which is its spf.
                    spf[j]=i;
                }
            }
        }
    }

    while(n!=1){
        cout<<spf[n]<<" ";
        n=n/spf[n];
    }
}






int main(){
    int n;
    cin>>n;
    
    primefactor(n);
    return 0;
}