// Problem Statement: Given an array print all the sum of the subset generated from it, in the increasing order.

// Input: N = 3, arr[] = {5,2,1}
// Output: 0,1,2,3,5,6,7,8

// Explanation: We have to find all the subset’s sum and print them.in this case the generated subsets are [ [], [1], [2], [2,1], [5], [5,1], [5,2]. [5,2,1] ],so the sums we get will be  0,1,2,3,5,6,7,8

#include <bits/stdc++.h>
using namespace std;

void findSub(int ind, vector<int> & arr, int n, vector<int> & ans, int sum){
    if(ind == n){
        ans.push_back(sum);
        return;
    }

    findSub(ind+1, arr, n, ans, sum+arr[ind]);
    findSub(ind+1, arr, n, ans, sum);
}

int main(){
    vector<int> ans;
    vector<int> arr = {5, 2, 1};
    int n = arr.size();
    findSub(0, arr, n, ans, 0);
    sort(ans.begin(), ans.end());
    for(auto x: ans){
        cout << x << " ";
    }
    return 0;
}