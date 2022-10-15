#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>> n >> m;

    int a[n][m];
    for(int i=0; i<n; i++){
       for(int j=0; j<m; j++){
           cin>> a[i][j];
       }
    }
    
    int target;
    cin>> target;

    int r=0, c=n-1;   // It is the top right position
    bool found = false;
    while(r<m && c>=0){
        if(target == a[r][c])
            found =true;
        // else if(target< a[r][c])
        //    c--;
        // else
        //    r++;
        a[r][c]<target ? r++: c--;
    }

    if(found)
      cout<<"Element exist";
    else
      cout<<"Element does not exist";

    return 0;
}