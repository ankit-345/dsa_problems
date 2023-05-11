// N Queen Problem 

// Problem Statement: The n-queens is the problem of placing n queens on n × n chessboard such that no two queens can attack each other. Given an integer n, return all distinct solutions to the n -queens puzzle. Each solution contains a distinct boards configuration of the queen’s placement, where ‘Q’ and ‘.’ indicate queen and empty space respectively.


// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]

#include <bits/stdc++.h>
#include <vector>
using namespace std;

// BETTER APPROACH:

bool isSafe1(int row, int col, vector<string> board, int n){
    int duprow = row;
    int dupcol = col;

    while(row >= 0 && col >= 0){
        if(board[row][col] == 'Q'){
            return false;
        }
        row--;
        col--;
    }

    col = dupcol;
    row = duprow;
    while(col >= 0){
        if(board[row][col] == 'Q'){
            return false;
        }
        col--;
    }

    col = dupcol;
    row = duprow;
    while(row<n && col >= 0){
        if(board[row][col] == 'Q'){
            return false;
        }
        row++;
        col--;
    }

    return true;
}

void solve(int col, vector<string> & board, vector<vector<string> > & ans, int n ){
   if(col == n){
     ans.push_back(board);
     return;
   }

   for(int row = 0; row<n; row++){
     if(isSafe1(row, col, board, n)){
        board[row][col] = 'Q';
        solve(col+1, board, ans, n);
        board[row][col] = '.';
     }
   }
}


// OPTIMAL APPROACH:

void solve2(int col, vector<string> & board, vector<vector<string> > & ans, int n, vector<int> & leftrow, vector<int> & lowerDiagonal, vector<int> & upperDiagonal){
    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int row=0; row<n; row++){
        if(leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n-1 + row - col] == 0){
            board[row][col] = 'Q';
            leftrow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[n-1 + row - col] = 1;

            solve2(col+1, board, ans, n, leftrow, lowerDiagonal, upperDiagonal);

            board[row][col] = '.';
            leftrow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[n-1 + row-col] = 0;
        }
    }
}

int main(){
    int n = 4;
    vector<vector<string> > ans;
    vector<string> board(n);
    string s(n, '.');
    for(int i=0; i<n; i++){
        board[i] = s;
    }
    vector<int> leftrow(n, 0), lowerDiagonal(2*n-1, 0), upperDiagonal(2*n-1, 0);
    
    // solve(0, board, ans, n);
    solve2(0, board, ans, n, leftrow, lowerDiagonal, upperDiagonal);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[0].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

