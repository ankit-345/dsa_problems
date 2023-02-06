// Pascals triangle

//         1
//       1   1
//     1   2   1
//   1   3   3  1
// 1   4   6   4  1

#include <bits/stdc++.h>
using namespace std;

vector< vector<int>> generate(int numRows){
    vector< vector<int> > r(numRows);

    for(int i=0; i<numRows; i++){
    // resizing means => first row should have one space, 2nd row should have second space and so-on.
        r[i].resize(i+1);
    
    
    // since in the start and diagonal of every row, there is 1.
    r[i][0] = r[i][i] = 1;

    // For the middle element and it will till the second last element thats what we want because at the start and end => we have 1.
    for(int j=1; j<i; j++){
        r[i][j] = r[i-1][j-1] + r[i-1][j];
    }
  }

  return r;
}

// Time Complexity: We are creating a 2D array of size (numRows * numCols) (where 1 <= numCols <= numRows), and we are traversing through each of the cells to update it with its correct value, so Time Complexity = O(numRows2).

// Space Complexity: Since we are creating a 2D array, space complexity = O(numRows2).
