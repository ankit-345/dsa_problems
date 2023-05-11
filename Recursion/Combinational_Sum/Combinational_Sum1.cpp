// Given an array of distinct integers and a target, you have to return the list of all unique combinations where the chosen numbers sum to target. You may return the combinations in any order.

// Input: array = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]

// Explanation: 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
//              7 is a candidate, and 7 = 7.
//              These are the only two combinations.

#include <bits/stdc++.h>
using namespace std;



void findCombination(int ind, int target, vector<int> & arr, vector<vector<int>> & ans, vector<int> & ds){
   if(ind == arr.size()){
    if(target == 0){
        // sort(ds.begin(), ds.end());
        ans.push_back(ds);
    }
    return;
   }

   // Pick the elements
   if(arr[ind] <= target){
    ds.push_back(arr[ind]);
    findCombination(ind, target-arr[ind], arr, ans, ds);
    ds.pop_back();
   }

   findCombination(ind+1, target, arr, ans, ds);
}

int main(){
    vector<vector<int>> ans;
    vector<int> ds;
    vector<int> arr = {4, 1, 9};
    findCombination(0, 9, arr, ans, ds);
    // sort(ans.begin(), ans.end());

    for(auto x: ans){
        for(auto i: x){
            cout << i << " " ;
        }
        cout << endl;
    }
}