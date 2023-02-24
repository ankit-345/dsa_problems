// Input: [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]

// Explanation: Rotate the matrix simply by 90 degree clockwise and return the matrix.

// -----------------------------------------------------------------------------------------------------------

// Approach 1: Using Dummy Array

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rotate(vector<vector<int>> & matrix){
    int n = matrix.size();
    vector<vector<int>> rotated(n, vector<int> (n, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            rotated[j][n-i-1] = matrix[i][j];
        }
    }
    return rotated;
}

// -----------------------------------------------------------------------------------------------------------

// Approach 2: 

void rotate2(vector< vector<int> > & matrix){
    int n = matrix.size();
    
    // Transposing the matrix
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            swap(matrix[j][i], matrix[i][j]);
        }
    }

    // Reversing each row
    for(int i=0; i<n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
}


// -----------------------------------------------------------------------------------------------------------

int main(){
    vector< vector<int> > arr={{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    // vector< vector<int> > ans = rotate(arr);
    rotate2(arr);
    
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // for(int i=0; i<ans.size(); i++){
    //     for(int j=0; j<ans[i].size(); j++){
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}