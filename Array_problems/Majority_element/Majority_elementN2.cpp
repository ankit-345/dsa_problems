// Majority Element (N/2)

// Input Format: N = 3, nums[] = {3,2,3}
// Result: 3
// Explanation: When we just count the occurrences of each number and compare with half of the size of the array, you will get 3 for the above solution. 

// Brute Force Approach: (using two loops)

#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> & arr, int n){
   vector<bool> visited(n, false);
   int m = n/2;
   int count, check;
   for(int i=0; i<n; i++){
     if(visited[i] == true){
        continue;
     }

     count = 1;
     for(int j=i+1; j<n; j++){
        if(arr[i] == arr[j]){
            visited[i] = true;
            count++;
        }
     }
     if(count > m){
        check = arr[i];
     }
   }
   return check;
}

// Better approach: (using map)
// here, we are reducing the searching amount by using a better data structure.

int majorityElement2(vector<int> & arr, int n){
   map<int, int> m;
   int mi = n/2;
   int check;
   for(int i=0; i<n; i++){
      m[arr[i]]++;
   }
   
   for(auto x: m){
    if(x.second > mi){
       check = x.first;
    }
   }
   return check;
}

// Optimal Approach: (Moore's Voting Algorithm)

int majorityElement3(vector<int> & arr, int n){
    int count = 0;
    int candidate = 0;

    for(int num: arr){
        if(count == 0){
            candidate= num;
        }
        if(count == candidate){
            count += 1;
        }
        else{
            count -= 1;
        }
    }
    return candidate;
}

int main(){
    vector<int> arr = {4,4,2,4,3,4,4,3,2,4};
    cout << majorityElement(arr, 10) << endl;
    cout << majorityElement2(arr, 10) << endl;
    cout << majorityElement3(arr, 10) << endl;
    return 0;
}