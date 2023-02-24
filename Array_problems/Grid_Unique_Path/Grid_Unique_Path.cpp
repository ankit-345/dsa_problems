// Problem Statement: Given a matrix m X n, count paths from left-top to the right bottom of a matrix with the constraints that from each cell you can either only move to the rightward direction or the downward direction.

// Input Format: m = 2, n= 2
// Output: 2
// Explanation: From the top left corner there are total 2 ways to reach the bottom right corner:

// Step 1: Right ->> Down
// Step 2: Down ->> Right

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach: (Recursion)
int countPaths(int i, int j, int n, int m){
    if(i>=n || j>=m) return 0;
    if(i == (n-1) && j == (m-1)) return 1;
    
    else {
        return countPaths(i+1, j, n, m) + countPaths(i, j+1, n, m);
    }
}


// Better Approach: (dynamic programming)

int countPaths2(int i, int j, int n, int m, vector<vector<int>> &dp){
    if(i>=n || j>=m) return 0;
    if(i == (n-1) && j == (m-1)) return 1;

    if(dp[i][j] != -1) return dp[i][j];
    else {
        return dp[i][j] = countPaths2(i+1, j, n, m, dp) + countPaths2(i, j+1, n, m, dp);
    }
}

// Optimal Approach: (Combinatrics solution)
int countPaths3(int n, int m){
    int N = m+n-2;
    int r = m-1;
    double res = 1;

    for(int i=1; i<=r; i++){
       res = res * (N-r+i)/i;
    }
    return (int)res;
}

int main(){
    int num1, num2, num3;
    int m=2, n=3;
    num1 = countPaths(0, 0, n, m);
    cout << "Through Recursion approach " << num1 << endl;

    vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
    num2 = countPaths2(0, 0, n, m, dp);
    cout << "Through dynamic programming " << num2 << endl;

    num3 = countPaths3(n, m);
    cout << "Through combinatrics method " << num3 << endl;
    return 0;
}