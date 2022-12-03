// Given an array a[] of size n. Output the sum of every subarray of the given arrays 

# include <bits/stdc++.h>
using namespace std;

int main(){

    int n,curr=0;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
       cin>>a[i];
    
    for(int i=0; i<n; i++){
        curr=0;
        for(int j=i; j<n; j++){
            curr+=a[j];
            cout<<curr<<" ";
        }
    }
    return 0;
}