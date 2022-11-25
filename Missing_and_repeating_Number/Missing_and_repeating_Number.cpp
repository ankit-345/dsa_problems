// Input Format:  array[] = {3,1,2,5,3}

// Result: {3,4)

// Explanation: A = 3 , B = 4 
// Since 3 is appearing twice and 4 is missing

// ----------------------------------------------------------------------------------------------->

// Approach 1: (USING COUNT SORT)

#include <bits/stdc++.h>
using namespace std;

vector<int> r_and_m(vector<int> & arr){
    int n = arr.size() + 1;
    vector<int> nums(n, 0);
    vector<int> ans;

    for(int i=0; i<n-1; i++){
        nums[arr[i]]++;
    }
    for(int i=1; i<n-1; i++){
        if(nums[i] > 1){
            ans.push_back(i);
        }
        else if(nums[i] == 0){
            ans.push_back(i);
        }
    }
    return ans;
}

// T.C => O(N)
// S.C => O(N)

// ----------------------------------------------------------------------------------------------->

// Approach 2: (USING MATHS)


vector<int> r_and_m2(vector<int> arr){
  long long int len = arr.size();

  long long int s = (len*(len+1))/2;                // sum of all the numbers from 1 to N
  long long int p = (len*(len+1)*(2*len + 1))/6;    // sum of squares of all the numbers from 1 to N

  long long int repeating = 0, missing = 0;
  for(int i=0; i<len; i++){ 
    s -= (long long int)arr[i];                     // sum obtained after subtracting (s) - (sum of all elements of arr) -----> eq 1
    p -= (long long int)arr[i] * (long long int)arr[i];   // sum obtained after subtracting (p) - (sum of squares of all elements of arr) ----> eq 2
  }

  missing = (p/s + s)/2;                // After solving both the equation, we get something like this
  
  repeating = missing - s;              // since, (missing - repeating = s) ==> (repeating = missing - s);

  vector<int> ans;
  ans.push_back(repeating);
  ans.push_back(missing);
  return ans;
}

// T.C. = O(N);
// S.C. = O(1);


// ----------------------------------------------------------------------------------------------->

// Approach 3: (USING XOR)

vector<int> r_and_m3(const vector<int> & arr){
     /* Will hold xor of all elements and numbers from 1 to n */
    int xor1;
    
      /* Will have only single set bit of xor1 */
    int set_bit_no;

    int i;
    int x = 0;  /* missing */
    int y = 0;  /* repeating */
    int n = arr.size();

    xor1 = arr[0];

    /* Get the xor of all array elements */
    for(i=1; i<n; i++){
        xor1 = xor1 ^ arr[i];
    }
    
    /* XOR the previous result with numbers from 1 to n */
    for(i=1; i<=n; i++){
        xor1 = xor1 ^ i;
    }
    
    /* Get the rightmost set bit in set_bit_no */
    set_bit_no = xor1 & ~(xor1 -1);
   
   /* Now divide elements into two sets by comparing a rightmost set bit
       of xor1 with the bit at the same position in each element.
       Also, get XORs of two sets. The two XORs are the output elements.
       The following two for loops serve the purpose */
    for(i=0; i<n; i++){
        if(arr[i] & set_bit_no){
            /* arr[i] belongs to first set */
            x = x ^ arr[i];
        }
        else{
             /* arr[i] belongs to second set */
            y = y ^ arr[i];
        }
    }

    for(i=1; i<=n; i++){
       if(i & set_bit_no){
        /* i belongs to first set */
         x = x ^ i;
       }
       else{
         /* i belongs to second set */
        y = y ^ i;
       }
    }

   
   // NB! numbers can be swapped, maybe do a check ?
    int n_count = 0;
    for(i=0; i<n; i++){
        if(arr[i] == n){
            n_count++;
        
        if(n_count == 0){
            return {y, x};
        }
        return {x, y};
    }
}
}

// T.C. = O(N);
// S.C = O(1);






// ----------------------------------------------------------------------------------------------->
int main(){
    vector<int> arr;
    arr = {4, 3, 6, 2, 1, 1};
    vector<int> ans(2, -1);
    // ans = r_and_m(arr);
    // ans = r_and_m2(arr);
    ans = r_and_m3(arr);
    for(auto e: ans){
        cout << e << " ";
    }
    return 0;
}