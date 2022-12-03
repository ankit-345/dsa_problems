#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;

    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    
    int x,i,j;
    cin>>x;
    bool flag=false;
     for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(a[i][j] == x){
                cout<<i<<" "<<j;
                flag=true;
                break;
            }
        }
    }

    if( flag == true)
       cout<<"\nElement is found" << endl;
    else
      cout<<"Element does not found" << endl;
    return 0;
}