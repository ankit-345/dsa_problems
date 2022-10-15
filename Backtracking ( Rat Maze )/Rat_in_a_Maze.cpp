#include <iostream>
#include <stdio.h>
using namespace std;

bool isSafe(int** arr,int x, int y, int n) // array is dynamic that's why 2 stars, x and y indicate the block
{
    if(x<n && y<n && arr[x][y] == 1){  // arr[x][y] == 1 because for blocks, 
        return true;                   // 1 => indicates can go, 0 => indicates cannot go
    }
    return false;
}

bool ratinMaze(int** arr, int x, int y, int n, int** solArr){  // solArr == solution array

   if(x == n-1 && y == n-1){   // base case
       solArr[x][y] = 1;
       return true;
   }


    if(isSafe(arr, x, y, n)){   // checking whether we can enter the block or not
        solArr[x][y] = 1;
        if(ratinMaze(arr, x+1, y, n, solArr)){  // recursive call for moving in right direction
            return true;
        }
        if(ratinMaze(arr, x, y+1, n, solArr)){  // recursive call for moving in downward direction    
            return true;
        }

        solArr[x][y] = 0;  // Incase, we receive false i.e. it returns false then we will mark it as 0 (backtracking)
        return false;
    } 
    return false;  
}


int main()
{
    int n;
    cin >> n;

     
    int** arr = new int*[n];     // Dynamic memory allocation for array
    for(int i=0; i<n; i++){
        arr[i] = new int[n];
    }
    

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j]; 
        }
    }

    int** solArr = new int*[n];     
    for(int i=0; i<n; i++){
        solArr[i] = new int[n];
        for(int j=0; j<n; j++){   // Initialising the solution array with zero 
            solArr[i][j] = 0;     // otherwise the compilar will give the garbage value
        }
    }

    if(ratinMaze(arr,0,0,n,solArr)){
        for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << solArr[i][j] << " ";
        }cout << endl;
    }
    }
    return 0;
}

// 1 0 1 0 1
// 1 1 1 1 1
// 0 1 0 1 0
// 1 0 0 1 1
// 1 1 1 0 1