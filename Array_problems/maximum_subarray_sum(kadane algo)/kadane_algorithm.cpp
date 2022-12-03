
// Approach 1: O(n3)
// Using three for loops, we will get all possible subarrays in two loops and their sum in another loop, and then return the maximum of them.

#include <bits/stdc++.h>
using namespace std;

// subarray ==> for storing the indices
int max_subarray(vector<int> &nums, vector<int> &subarray){
    int n = nums.size();
    int max_sum = INT_MIN;
    if(n == 1){
        return nums[0];
    }
    else{
        int i,j;
        int sum = 0;
        for(i=0; i<n; i++){
            for(j=1; j<n; j++){
                  sum = 0;
                  for(int k=i; k<=j; k++){
                    sum += nums[k];
                  }
                  if(sum > max_sum){
                    max_sum = sum;
                    subarray.clear();
                    subarray.push_back(i);
                    subarray.push_back(j); 
                  }
            }
        }
        return max_sum;
    }
}

// ------------------------------------------------------------------------------------------------------->

// Approach 2: O(n2)
// We can also do this problem using only two for loops, we will avoid 3rd loop which was used in above approach, instead of that we will create new variable curr_sum, which stores the array sum from ith index to jth index.

int max_subarray2(vector<int> & nums, vector<int> & subarray){
    int max_sum = INT_MIN;
    int cur_sum = 0;
    int n = nums.size();
    if(n == 1){
        return nums[0];
    }
    int i,j;
    for(i=0; i<n; i++){
        cur_sum = 0;
        for(j=i; j<n; j++){
            cur_sum += nums[j];
            if(cur_sum > max_sum){
                subarray.clear();
                max_sum = cur_sum;
                subarray.push_back(i);
                subarray.push_back(j);
            }
        }
    }
    return max_sum;
}
// ------------------------------------------------------------------------------------------------------->

// Approach 3(Kadane's Algorithm): O(n)    (IMPORTANT)

int max_subarray3(vector<int> & nums, vector<int> & subarray){
    int sum = 0;
    int max_sum = INT_MIN;
    int s = 0;   // starting index of the result subarray;
    int n = nums.size();
    for(int i=0; i<n; i++){
        sum += nums[i];
        if(sum > max_sum){
            subarray.clear();
            max_sum = sum;
            subarray.push_back(s);
            subarray.push_back(i);
        }

        if(sum < 0){
            sum = 0;
            s = i+1;
        }
    }
    return max_sum;
}
// // ------------------------------------------------------------------------------------------------------->

int main() {
//   vector<int> arr{-2,1,-3,4,-1,2,1,-5,4};
  vector<int> arr{-7, -8, -16, -4, -8, -5, -7, -11, -10, -12, -4, -6, -4, -16, -10};
  vector < int > subarray;
//   int lon = max_subarray(arr, subarray);
//   int lon = max_subarray2(arr, subarray);
  int lon = max_subarray3(arr, subarray);
  cout << "The longest subarray with maximum sum is " << lon << endl;
  cout << "The subarray is " << endl;
  for (int i = subarray[0]; i <= subarray[1]; i++) {
    cout << arr[i] << " ";
  }
 return 0;
}