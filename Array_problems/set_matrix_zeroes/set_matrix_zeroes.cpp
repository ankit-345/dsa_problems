#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE APPROACH

void setZeroes(vector<vector<int>> & matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == 0){

                // This is for the columns;
                int ind = i-1;
                while(ind >= 0){
                    if(matrix[ind][j] != 0){
                        matrix[ind][j] = -1;
                    }
                    ind--;
                }

                ind = i+1;
                while(ind < n){
                    if(matrix[ind][j] != 0){
                        matrix[ind][j] = -1;
                    }
                    ind++;
                }
               
               // This is for the rows;
               ind = j-1;
               while(ind >= 0){
                 if(matrix[i][ind] != 0){
                       matrix[i][ind] = -1;
                 }
                 ind--;
               }

               ind = j+1;
               while(ind < m){
                 if(matrix[i][ind] != 0){
                    matrix[i][ind] = -1;
                 }
                 ind++;
               }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] <= 0){
                matrix[i][j] = 0;
            }
        }
    }
}

// ------------------------------------------------------------------------------------------------------------------
// BETTER APPROACH

void setZeroes2(vector< vector<int> > & matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> dummy1(n, -1), dummy2(m, -1);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == 0){
                dummy1[i] = 0;
                dummy2[j] = 0;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(dummy1[i] == 0 || dummy2[j] == 0){
                matrix[i][j] = 0;
            }
        }
    }
}


// ------------------------------------------------------------------------------------------------------------------

// BEST APPROACH

void setZeroes3(vector< vector<int> > & matrix){
    int col = 1, n = matrix.size(), m = matrix[0].size();

    for(int i=0; i<n; i++){
        if(matrix[i][0] == 0)
            col = 0;
        
        for(int j=1; j<m; j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }

    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=1; j--){
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
        if(col == 0){
            matrix[i][0] = 0;
        }
    }
}
// ------------------------------------------------------------------------------------------------------------------


int main() {
  vector < vector < int >> arr;
  arr = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
//   setZeroes(arr);
// setZeroes2(arr);
setZeroes3(arr);
  cout << "The Final Matrix is " << endl;
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[0].size(); j++) {
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }
}
