#include <bits/stdc++.h>
using namespace std;

//Input: x = 2.00000, n = 10
// Output: 1024.00000
// Explanation: You need to calculate 2.00000 raised to 10 which gives ans 1024.00000

// Brute approach

double myPow(double x, int n){
   double ans = 1.0;

   for(int i=0; i<n; i++){
    ans = ans * x;
   }

   return ans;
}

double myPow2(double x, int n){
    double ans = 1.0;
    long long nn = n;
    if(nn < 0) 
       nn = -1 * nn;
    while(nn){
        if(nn % 2){
            ans = ans * x;
            nn = nn - 1;
        }
        else{
            x = x * x;
            nn = nn / 2;
        }
    }

    if(n < 0)
      ans = (double) (1.0)/(double) (ans);
    return ans;
}

int main(){
    double x = 2.00000;
    int n = 10;

    cout << myPow(x, n) << endl;
    cout << myPow2(x, n) << endl;
    return 0;
}