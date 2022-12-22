// Approach 1:

// 1) sort the array
// 2) T.C. => O(NlogN), S.C. => O(1)

// ------------------------------------------------------------------------------------------------->

// Approach 2:

// -> Keeping the count of occurances of 0, 1 and 2;
// -> And then put it back into the array.

// -> T.C. => O(N) + O(N), S.C. => O(1)


// ------------------------------------------------------------------------------------------------->

// Approach 3:  USE DNF( Dutch National Flag ) ALOGRITHM ( 3 Pointer Approach )

#include <bits/stdc++.h>
using namespace std;

void dnfSort(vector<int> &nums){
    int n = nums.size();
    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid <= high){
        if(nums[mid] == 0){
            swap(nums[low], nums[mid]);
            low++; mid++;
        }
        else if(nums[mid] == 1){
            mid++;
        }
        else{
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main(){
    vector<int> nums = {0, 1, 0, 1, 1, 0, 2, 1, 0, 2};
    dnfSort(nums);
    for(auto ele : nums){
        cout << ele << " ";
    }
    return 0;
}


