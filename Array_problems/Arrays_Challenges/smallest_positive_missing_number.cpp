# include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int N=1e6 +2;
    bool check[N];

    for(int i=0;i<N;i++){
        check[i] = 0;  // Intialise the array check[] with false i.e. 0
    }

    for(int i=0;i<n;i++){
        if(a[i] >=0){
            check[a[i]] = 1;    // If a non-negative number is encountered then mark true i.e. 1 at the index whose value is equal to the value of array
        }
    }
      int ans = -1;
    for(int i=1; i<N; i++){
        if( check[i] == false ){  // whenever first false is encountered, store the index (i) in ans variable and break the loop
            ans = i;
            break;
        }
    }

    cout<<ans<<endl;
    return 0;
}