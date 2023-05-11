// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N – 1, N – 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are ‘U'(up), ‘D'(down), ‘L’ (left), ‘R’ (right). Value 0 at a cell in the matrix represents that it is blocked and the rat cannot move to it while value 1 at a cell in the matrix represents that rat can travel through it.

// Note: In a path, no cell can be visited more than one time.
// Print the answer in lexicographical(sorted) order

// Input:
// N = 4
// m[][] = {{1, 0, 0, 0},
//         {1, 1, 0, 1}, 
//         {1, 1, 0, 0},
//         {0, 1, 1, 1}}

// Output: DDRDRR DRDDRR

// Explanation:
// The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.

#include <bits/stdc++.h>
#include <vector>
using namespace std;

void solve(int i, int j, vector<vector<int>> & a, int n, vector<string> & ans, string move, vector<vector<int>> &vis ){
    if(i==n-1 && j==n-1){
        ans.push_back(move);
        return;
    }

    //Downward
    if(i+1<n && !vis[i+1][j] && a[i+1][j] == 1){
        vis[i][j] = 1;
        solve(i+1, j, a, n, ans, move + 'D', vis);
        vis[i][j] = 0;
    }

    //Left
    if(j-1>0 && !vis[i][j-1] && a[i][j-1] == 1){
        vis[i][j] = 1;
        solve(i, j-1, a, n, ans, move + 'L', vis);
        vis[i][j] = 0;
    }

    //Right
    if(j+1 < n && !vis[i][j] && a[i][j+1] == 1){
        vis[i][j] = 1;
        solve(i, j+1, a, n, ans, move + 'R', vis);
        vis[i][j] = 0;
    }

    //Upward
    if(i-1>0 && !vis[i-1][j] && a[i-1][j] == 1){
        vis[i][j] = 1;
        solve(i-1, j, a, n, ans, move + 'U', vis);
        vis[i][j] = 0;
    }
}

// Optimised approach:

void solve2(int i, int j, vector<vector<int>> &a, int n, vector<vector<int>> &ans, vector<int> &move, vector<vector<int>> &vis, int di[], int dj[]){
    if(i==n-1 && j==n-1){
        int count = 0;
        for(int x = 0; x<n; x++){
            for(int y=0; y<n; y++){
                move[count++] = vis[x][y];
            }
        }
        move[move.size() - 1] = 1;
        ans.push_back(move);
        fill(move.begin(), move.end(), 0);
        return;
    }

    string dir = "DLRU";
    for(int ind=0; ind<4; ind++){
        int nexti = i + di[ind];
        int nextj = j + dj[ind];
        if(nexti>=0 && nextj>=0 && nexti<n && nextj<n && !vis[nexti][nextj] && a[nexti][nextj] == 1){
            vis[i][j] = 1;
            solve2(nexti, nextj, a, n, ans, move, vis, di, dj);
            vis[i][j] = 0;
        }
    }
}

int main(){
    vector < vector < int >> a = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    int n = 4;
    vector<vector<int>> ans;
    vector<int> move(n*n, 0);
    vector<vector<int>> vis(n, vector<int> (n, 0));
    int di[] = {+1, 0, 0, -1};
    int dj[] = {0, -1, 1, 0};

    // if(a[0][0]) solve(0, 0, a, n, ans, "", vis);
    if(a[0][0]) solve2(0, 0, a, n, ans, move, vis, di, dj);

    
    for(auto i: ans){
        for(auto x: i){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}