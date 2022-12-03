/* Input: 
 n = 4, arr1[] = [1 4 8 10] 
 m = 5, arr2[] = [2 3 9]

 Output: 
 arr1[] = [1 2 3 4]
 arr2[] = [8 9 10]
*/ 

// -------------------------------------------------------------------------------------------->

// Approach 1: (using 3rd Array)

/* 
-- Make an arr3 of size n+m.
-- Put elements arr1 and arr2 in arr3.
-- Sort the arr3.
-- Now first fill the arr1 and then fill remaining elements in arr2. 
*/

// Time complexity: O(n*log(n))+O(n)+O(n)
// Space Complexity: O(n) 

// -------------------------------------------------------------------------------------------->

// Approach 2: (without using extra space)

/* 
-- Use a for loop in arr1.
-- Whenever we get any element in arr1 which is greater than the first element of arr2,swap it.
-- Rearrange arr2.(that means sort it again)
-- Repeat the process.
*/

#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int b[], int n, int m){
    int i, k;
    for(int i=0; i<n; i++){
        if(a[i] > b[0]){
            int temp = a[i];
            a[i] = b[0];
            b[0] = temp;
        }

       // Insertion Sort is used here
        int first = b[0];
        for(k = 1; k<m && b[k] < first; k++){
            b[k-1] = b[k];
        }
        b[k-1] = first;
    }
}

// Time complexity: O(n*m)
// Space Complexity: O(1) 

// -------------------------------------------------------------------------------------------->

// Approach 3: (Gap Method)

/*
-- Initially take the gap as (m+n)/2;
-- Take as a pointer1 = 0 and pointer2 = gap.
-- Run a oop from pointer1 &  pointer2 to  m+n and whenever arr[pointer2]<arr[pointer1], just swap those.
-- After completion of the loop reduce the gap as gap=gap/2.
-- Repeat the process until gap>0.
*/

int nextgap(int gap){
    if(gap <= 1){
        return 0;
    }
    return (gap / 2) + (gap % 2);
}

void merge2(int* arr1, int* arr2, int n, int m){
    int i,j, gap = n+m;

    for(gap = nextgap(gap); gap>0; gap = nextgap(gap)){

        // comparing elements in the first array
        for(i=0; i+gap<n; i++){
          if(arr1[i] > arr1[i+gap]){
            swap(arr1[i], arr1[i+gap]);
          }
        }

        // comparing elements in the first and second array
        for(j = gap>n? gap-n: 0; i<n & j<m; i++, j++){
            if(arr1[i] > arr2[j]){
                swap(arr1[i], arr2[j]);
            }
        }

        if(j<m){
            // comparing elements in second array
            for(j=0; j+gap<m; j++){
                if(arr2[j] > arr2[j+gap]){
                    swap(arr2[j], arr2[j+gap]);
                }
            }
        }
    }
}
// -------------------------------------------------------------------------------------------->
int main() {
  int arr1[] = {1,4,7,8,10};
  int arr2[] = {2,3,9};
  cout << "Before merge:" << endl;
  for (int i = 0; i < 5; i++) {
    cout << arr1[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < 3; i++) {
    cout << arr2[i] << " ";
  }
  cout << endl;
  merge2(arr1, arr2, 5, 3);
  cout << "After merge:" << endl;
  for (int i = 0; i < 5; i++) {
    cout << arr1[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < 3; i++) {
    cout << arr2[i] << " ";
  }
  return 0;
}
