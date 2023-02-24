// MAJORITY ELEMENT (N/3)

// Input:  N = 6, array[] = {11,33,33,11,33,11}
// Output: 11 33
// Explanation: Here we can see that the Count(11) = 3 and Count(33) = 3. Therefore, the count of both 11 and 33 is greater than N/3 times. Hence, 11 and 33 is the answer.

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach (using two loops)

vector<int> majorityElement(int arr[], int n){
   vector<int> ans;
   for(int i=0; i<n; i++){
    int cnt = 1;
    for(int j=i+1; j<n; j++){
        if(arr[i] == arr[j]){
            cnt++;
        }
    }
    if(cnt > (n/3)){
        ans.push_back(arr[i]);
    }
   }
   return ans;
}

// Better Approach: (using hashmap)

vector<int> majorityElement2(int arr[], int n){
    vector<int> ans;
    map<int, int> m;
    for(int i=0; i<n; i++){
        m[arr[i]]++;
    }
    for(auto x: m){
        if(x.second > (n/3)){
            ans.push_back(x.first);
        }
    }
    return ans;
}

// Optimal Approach: (Extended Boyer Moore's Voting Algorithm)
vector<int> majorityElement3(int arr[], int n){
    int sz = n;
    int count1 = 0, count2 = 0, num1 = -1, num2 = -1, i;
    for(i=0; i<sz; i++){
        if(arr[i] == num1){
            count1++;
        }
        else if(arr[i] == num2){
            count2++;
        }
        else if(count1 == 0){
            num1 = arr[i];
            count1 = 1;
        }
        else if(count2 == 0){
            num2 = arr[i];
            count2 = 1;
        }
        else{
            count1--;
            count2--;
        }
    }
   
    vector<int> ans;
    count1 = 0, count2 = 0;
    for(i=0; i<sz; i++){
        if(num1 == arr[i]){
            count1++;
        }
        else if(num2 == arr[i]){
            count2++;
        }
    }
        if(count1 > (sz/3)){
            ans.push_back(num1);
        }
        if(count2 > (sz/3)){
            ans.push_back(num2);
        }
    return ans;
}


int main(){
    int arr[] = {11,33,33,11,33,11};
    vector<int> ans;
    ans = majorityElement(arr, 6);
    for(auto x: ans){
        cout << x << " ";
    }
    cout << endl;
    vector<int> ans2;
    ans2 = majorityElement2(arr, 6);
    for(auto x: ans2){
        cout << x << " ";
    }
    cout << endl;
    vector<int> ans3;
    ans3 = majorityElement3(arr, 6);
    for(auto x: ans3){
        cout << x << " ";
    }
    return 0;
}