// LONGEST ARITHMETIC SUBARRAY


#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int ans=2;         // because the minimun length of the sub array will be 2.
    int pd=a[1]-a[0];  // to calculate the starting difference that means previous difference 
    int curr=2;        // because the current is a[0],a[1] only
    int j=2;           // because next is 2 after a[0],a[1]

    while(j<n)
    {
        if(pd == a[j]-a[j-1])  // equating previous difference with the current difference
        {
            curr++;
        }
        else{
            pd = a[j]-a[j-1];  // If it is not equal then the current difference will be stored in the previous difference
            curr=2;
        }
        ans=max(ans, curr);
        j++;
    }
    cout<<ans<<endl;
    return 0;

}