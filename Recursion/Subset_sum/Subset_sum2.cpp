// Problem Statement: Given an array of integers that may contain duplicates the task is to return all possible subsets. Return only unique subsets and they can be in any order.

// Input: array[] = [1,2,2]
// Output: [ [ ],[1],[1,2],[1,2,2],[2],[2,2] ]

// Explanation: We can have subsets ranging from  length 0 to 3. which are listed above. Also the subset [1,2] appears twice but is printed only once as we require only unique subsets.

#include <bits/stdc++.h>
using namespace std;

// Brute Force approach: Using HashSet to store the unique combination

void fun(int ind, vector<int> & arr, vector<int> &ds, set<vector<int>> & res){
    if(ind == arr.size()){
        sort(ds.begin(), ds.end());
        res.insert(ds);
        return;
    }

    ds.push_back(arr[ind]);
    fun(ind+1, arr, ds, res);

    ds.pop_back();
    fun(ind+1, arr, ds, res);
}

 void fun2(int ind, vector<int> & nums, vector<vector<int>> & ans, vector<int> & ds){
       ans.push_back(ds);
        
       for(int i=ind; i<nums.size(); i++){
           if(i != ind && nums[i] == nums[i-1]) continue;
           ds.push_back(nums[i]);
           fun2(i+1, nums, ans, ds);
           ds.pop_back();
       }
   }


int main(){
    vector<vector<int> > ans;
    set<vector<int>> res;
    vector<int> ds;

    vector<int> arr = {1, 2, 2};
    // fun(0, arr, ds, res);
    fun2(0, arr, ans, ds);

    // for(auto it = res.begin(); it != res.end(); it++){
    //     ans.push_back(*it);
    // }

    for(auto x: ans){
        for(auto i: x){
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}


// Optimal Appraoch: