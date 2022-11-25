// FIND THE DUPLICATE NUMBER

// Approach 1: (USING SORTING)

// Sort the array. After that, if there is any duplicate number they will be adjacent.So we simply have to check if arr[i]==arr[i+1] and if it is true,arr[i] is the duplicate number.( but it will distort the array )

// Time Complexity: O(NlogN);  logN => sorting the array,  N => traversing for finding tha adjacent array
// S.C. => O(1);

// ------------------------------------------------------------------------------------------------------------------------

// Approach 2: (USING FREQUENCY ARRAY)

// Take a frequency array of size N+1 and initialize it to 0. Now traverse through the array and if the frequency of the element is 0 increase it by 1, else if the frequency is not 0 then that element is the required answer.

// Time Comp.: O(N)
// S.C : O(N)

#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &arr){
  int n = arr.size();
  int b[n];
  int count;
  for(int i=0; i<n; i++){
    b[i] = 0;
  }
  for(int i=0; i<n; i++){
    if(b[arr[i]] == 0){
        b[arr[i]]++;
    }
    else{
       count = arr[i];
    }
  }
  return count;
}



// ------------------------------------------------------------------------------------------------------------------------

// Approach 3: (Linked List Cycle: method)

int findDuplicate2(vector<int> & arr){
    int slow = arr[0];
    int fast = arr[0];

    do{
        slow = arr[slow];
        fast = arr[arr[fast]];
    }while(slow != fast);

    fast = arr[0];
    while(slow != fast){
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}

int main(){
    vector<int> arr;
    arr = {1, 3, 4, 2, 2};
    cout << "Duplicate Number is " << findDuplicate(arr) << endl;
    cout << "Duplicate Number is " << findDuplicate2(arr) << endl;
    return 0;
}


// T.C => O(N)
// S.C => O(1)