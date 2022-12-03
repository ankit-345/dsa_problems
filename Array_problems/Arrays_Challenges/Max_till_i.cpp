// Given an array of size n .For every i till 0 to n-1,
// Output max(a[0], a[1],..., a[i])

# include <bits/stdc++.h>
using namespace std;

int main(){

    int mx=-199999;
    int n;
    cout<<"enter the size of an array:";
    cin>>n;
    int a[n];
    cout<<"enter the elements of an array:";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        mx=max(mx,a[i]);
        cout<<mx<<endl;
    }
  return 0;
}