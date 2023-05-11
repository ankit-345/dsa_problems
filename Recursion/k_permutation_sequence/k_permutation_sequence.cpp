// Problem Statement: Given N and K, where N is the sequence of numbers from 1 to N([1,2,3….. N]) find the Kth permutation sequence.

// For N = 3  the 3!  Permutation sequences in order would look like this:-
// k=1 --> "123"
// k=2 --> "132"
// k=3 --> "213"
// k=4 --> "231"
// k=5 --> "312"
// k=6 --> "321"

// Note: 1<=K<=N! Hence for a given input its Kth permutation always exists

// Input: N = 3, K = 3 
// Output: “213”

// Explanation: The sequence has 3! permutations as illustrated in the figure above. K = 3 corresponds to the third sequence.

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach:

void swap(string &s, int start, int end){
   char temp = s[start];
   s[start] = s[end];
   s[end] = temp;
}

void permutationHelper(string &s, int ind, vector<string> & ans){
    if(ind == s.size()){
        ans.push_back(s);
        return;
    }

    for(int i =ind; i<s.size(); i++){
        swap(s, ind, i);
        permutationHelper(s, ind+1, ans);
        swap(s, ind, i);
    }
}

string getPermutation(int n, int k){
    vector<string> ans;
    string s;

    // Creating a string   
    for(int i=1; i<=n; i++){
        s.push_back(i + '0');
    }

    permutationHelper(s, 0, ans);
    sort(ans.begin(), ans.end());
    
    // storing the address of the answer
    auto it = ans.begin() + (k-1);
    return *it;
} 





// OPTIMAL APPROACH:

string getPermutation2(int n, int k){
    int fact = 1;
    vector<int> numbers;
    for(int i=1; i<n; i++){
        fact = fact * i;
        numbers.push_back(i);
    }
    numbers.push_back(n);

    string ans = "";
    k = k-1;
    while(true){
        ans = ans + to_string(numbers[k/fact]);
        numbers.erase(numbers.begin() + k/fact);
        if(numbers.size() == 0){
            break;
        }
        k = k % fact;
        fact = fact / numbers.size();
    }
    return ans;
}

int main(){
    int n = 3, k = 3;
    cout << getPermutation(n, k) << endl;
    cout << getPermutation2(n, k) << endl;
    return 0;
}

