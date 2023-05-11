// Problem Statement: Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target. Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

// Input: candidates = [10,1,2,7,6,1,5], target = 8

// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]]

#include <bits/stdc++.h>
using namespace std;

void findCombination(int ind, int target, vector<int> & arr, vector<vector<int> > & ans, vector<int> & ds){
    if(target == 0){
        ans.push_back(ds);
        return;
    }

    for(int i=ind; i<arr.size(); i++){
        if(i>ind && arr[i] == arr[i-1]) continue;
        if(arr[i] > target) break;

        ds.push_back(arr[i]);
        findCombination(i+1, target-arr[i], arr, ans, ds);
        ds.pop_back();
    }
}


int main(){
    vector<vector<int>> ans;
    vector<int> ds;
    vector<int> arr = {10,1,2,7,6,1,5};
    sort(arr.begin(), arr.end());
    findCombination(0, 8, arr, ans, ds);

    for(auto x: ans){
        for(auto i : x){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}