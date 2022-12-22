// Input format: Arr[] = {1,3,2}

// Output: Arr[] = {2,1,3}

// Explanation: All permutations of {1,2,3} are {{1,2,3} , {1,3,2}, {2,13} , {2,3,1} , {3,1,2} , {3,2,1}}. So, the next permutation just after {1,3,2} is {2,1,3}.

// ------------------------------------------------------------------------------------------------------>

// Approach 1: Find all possible permutation

// -> Find all possible permutations of elements present and store them.
// -> Search input from all possible permutations.
// -> Print the next permutation present right after it.

// LOOK FOR ANSWERS IN THE RECURSION & BACKTRACKING SECTION


// ------------------------------------------------------------------------------------------------------>

// APPROACH 2: Using In-Built Function
#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> & nums){
    int n = nums.size();
    next_permutation(nums.begin(), nums.end());
}

// ------------------------------------------------------------------------------------------------------>

// Approach 3: 

void nextPermutation2(vector<int> & nums){
    int n = nums.size(), k, l;
    
    // For finding the break-point in the array
    for(k=n-2; k>=0; k--){
        if(nums[k] < nums[k+1]){
            break;
        }
    }
    
    // If there is no break-point, then it must be the largest lexicographical permutation.
    // Then by reverse the nums array, we get the first permutation which is our answers
    if(k<0){
        reverse(nums.begin(), nums.end());
    }
    
    // Here, we are finding the element which is greater than the break-point.
    for(l = n-1; l>k; l--){
        if(nums[l] > nums[k]){
            break;
        }
    }
    
    // Then swap both the numbers.
    swap(nums[l], nums[k]);

    // Then reverse the array from index+1 from step 1 to the end of the array. 
    reverse(nums.begin() + k + 1, nums.end());
}


// ------------------------------------------------------------------------------------------------------>
int main(){
    vector<int> nums = {1, 3, 2};
    // nextPermutation(nums);
    nextPermutation2(nums);
    for(auto i : nums){
        cout << i << " ";
    }
    return 0;
}

