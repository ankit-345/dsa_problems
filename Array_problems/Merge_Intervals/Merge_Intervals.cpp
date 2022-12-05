// Appraoch 1: Brute Force

#include <bits/stdc++.h>
using namespace std;

vector< pair<int, int> > merge(vector< pair<int, int>> & arr){
    int n = arr.size();

    // remember to sort the array.
    sort(arr.begin(), arr.end());
    vector< pair<int, int> > ans;

    for(int i=0; i<n; i++){
        int start = arr[i].first, end = arr[i].second;

        // Checking whether the recently selected element is part of a already selected element or not.
        // If it already a part, then just continue;
        if(!ans.empty()){
            if(start <= ans.back().second){
                continue;
            }
        }
        
        // This element is used to gather all the elements that lie in the intervals
        for(int j=i+1; j<n; j++){
            if(arr[j].first <= end){
               end = max(arr[j].second, end);
            }
        }

        end = max(arr[i].second, end);

        ans.push_back({start, end});
    }
    return ans;
}

// Time Complexity: O(NlogN)+O(N*N). O(NlogN) for sorting the array, and O(N*N) because we are checking to the right for each index which is a nested loop.


// ----------------------------------------------------------------------------------------------------->

// Approach 2: Optimal Approach

vector< vector<int>> merge(vector<vector<int>> & intervals){

    vector< vector<int> > mergedIntervals;
    if(intervals.size() == 0){
        return mergedIntervals;
    }

    sort(intervals.begin(), intervals.end());
    vector<int> tempIntervals = intervals[0];

    for(auto it: intervals){
        // If it is true that means (it) element lie in the intervals
        if(it[0] <= tempIntervals[1]){
            tempIntervals[1] = max(it[1], tempIntervals[1]);
        }
        else{
            mergedIntervals.push_back(tempIntervals);
            tempIntervals = it;
        }
    }

    // push the last tempIntervals in the mergeIntervals
    mergedIntervals.push_back(tempIntervals);

    return mergedIntervals;
}


// Time Complexity: O(NlogN) + O(N). O(NlogN) for sorting and O(N) for traversing through the array.


// ----------------------------------------------------------------------------------------------------->
int main() {
    // vector < pair < int, int >> arr;
    // arr = {{1,3},{2,4},{2,6},{8,9},{8,10},{9,11},{15,18},{16,17}};
    // vector < pair < int, int >> ans = merge(arr);

     vector < vector < int >> arr;
  arr = {{1, 3}, {2, 4}, {2, 6}, {8, 9}, {8, 10}, {9, 11}, {15, 18}, {16, 17}};
  vector < vector < int >> ans = merge(arr);

    cout << "Merged Overlapping Intervals are " << endl;

    for (auto it: ans) {
        cout << it[0] << " " << it[1] << "\n";
    }
}