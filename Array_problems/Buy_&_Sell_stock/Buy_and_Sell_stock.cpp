// i/p: prices = [7, 1, 5, 3, 6, 4]
// o/p: 5

// Explain: Buying on day 2 (price = 1) & sell on day 5 (price = 6), profit = 6-1 = 5.

//------------------------------------------------------------------------------------------------------------

// Approach 1: 

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> & arr){
    int n = arr.size();
    int maxPro = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[j] > arr[i]){
                maxPro = max(maxPro, arr[j] - arr[i]);
            }
        }
    }
    return maxPro;
}

//------------------------------------------------------------------------------------------------------------

int maxProfit2(vector<int>& arr){
    int n = arr.size();
    int maxPro = 0;
    int minPrice = INT_MAX;

    for(int i=0; i<n; i++){
        minPrice = min(minPrice, arr[i]);
        maxPro = max(maxPro, arr[i] - minPrice);
    }
    return maxPro;
}
//------------------------------------------------------------------------------------------------------------
int main(){
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    // int maxPro = maxProfit(arr);
    int maxPro = maxProfit2(arr);
    cout << maxPro << " ";
    return 0;
}