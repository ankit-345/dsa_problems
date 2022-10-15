# include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
     int maxsum = INT_MIN;    // we need to add <client.h> header to use it.
        for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
               
               sum+=a[k];
            }
          maxsum = max(sum,maxsum);  
        }
    }
    cout<<maxsum;
 return 0;
}