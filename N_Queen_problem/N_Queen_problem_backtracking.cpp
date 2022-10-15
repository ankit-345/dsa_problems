#include <iostream>
#include <stdio.h>
using namespace std;

bool isSafe(int** arr, int x, int y, int n){

    for(int row=0; row<x; row++){  // we are checking the queen row-wise
        if(arr[row][y] == 1){     // if the queen is found then return false
            return false;
        }
    }

    int row = x;
    int col = y;

    while(row>=0 && col>=0){   // checking for diagonally upward-left (\) that's why it is 0 0
        if(arr[row][col] == 1){   // checking whether the queen is present 
            return false;
        }
        row--;        
        col--;
    }
    
    row = x;
    col = y;
     while(row>=0 && col<n){   // checking for diagonally upward-right (/) that's why it is 0 n
        if(arr[row][col] == 1){   // checking whether the queen is present 
            return false;
        }
        row--;        
        col++;
    }

    return true; // if no-one is returning false then return true;
}
 
bool nQueen(int** arr, int x, int n) // when we place a queen, we jump in the next row and don't go to the next col.
{
    if(x>=n){  // when all the queens is placed
        return true;
    }

    for(int col=0; col<n; col++){  // col means x-axis
        if(isSafe(arr, x, col, n)){
            arr[x][col] = 1;
            if(nQueen(arr,x+1,n)){   // if it is giving true
                return true;         // then return true
            }

            arr[x][col] = 0;         // if it is giving false, then mark 0 means false
        }
    }
    return false;   // if we are not able to place the queen in all the columns then return false 
}

int main(){
   
   int n;
   cin >> n;

   int** arr = new int*[n];     // Dynamically allocating the memory for the array
   for(int i=0; i<n; i++){
      arr[i] = new int[n];
      for(int j=0; j<n; j++){   // Initialising the array by zero
        arr[i][j] = 0;          // so that it doesn't give garbage value
      }
   }

   if(nQueen(arr,0,n)){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }cout << endl;
    }
   }
   return 0;
}