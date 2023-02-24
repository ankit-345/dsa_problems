// Problem Statement: Given an array of numbers, you need to return the count of reverse pairs. Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].

// Input: N = 5, array[] = {1,3,2,3,1)
// Output: 2 
// Explanation: The pairs are (3, 1) and (3, 1) as from both the pairs the condition arr[i] > 2*arr[j] is satisfied.

#include <bits/stdc++.h>
using namespace std;

// Brute Force approach

int reversePairs(vector<int> & arr){
   int pairs = 0;
   for(int i=0; i<arr.size(); i++){
    for(int j=i+1; j<arr.size(); j++){
        if(arr[i] > (2*arr[j]))
          pairs++;
    }
   }
   return pairs;
}

int merge(vector<int> &arr, int low, int mid, int high){
    int total = 0;
    int j = mid+1;
    for(int i=low; i<=mid; i++){
       while(j<=high && (arr[i] > (2LL *arr[j]))){
          j++;
       }
       total += (j-(mid+1));
    }

    vector<int> temp;
    int left = low, right = mid+1;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left++]);
        }
        else{
            temp.push_back(arr[right++]);
        }
    }

    while(left<=mid){
        temp.push_back(arr[left++]);
    }

    while(right<=high){
        temp.push_back(arr[right++]);
    }

    for(int i=low; i<=high; i++){
        arr[i] = temp[i - low];
    }
    return total;
}

int mergeSort(vector<int> & arr, int low, int high){
    if(low>=high) return 0;
       int inv = 0;
       int mid = (low+high)/2;
       inv += mergeSort(arr, low, mid);
       inv += mergeSort(arr, mid+1, high);
       inv += merge(arr, low, mid, high);
    return inv;
}


int main(){
    vector<int> arr = {3, 4, 7, 7, 3, 1, 5, 1 };
    int ans = reversePairs(arr);
    cout << ans << endl;

    int ans2 = mergeSort(arr, 0, arr.size()-1);
    cout << ans2;
    return 0;
}