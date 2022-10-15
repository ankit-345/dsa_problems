# include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    const int N = 1e6+2;
    int ai[N];
    for(int i=0;i<N;i++){
        ai[i] = -1;
    }
    int mindex = INT_MAX;

    for(int i=0;i<n;i++){

        if ( ai[a[i]] != -1){
            mindex = min(mindex, ai[a[i]]);
        }
        else{

            ai[a[i]] = i;
        }
    }

    if( mindex == INT_MAX){
        cout<<"-1"<<endl;
    }
    else{
        cout << mindex+1<<endl;
    }

    return 0;
}