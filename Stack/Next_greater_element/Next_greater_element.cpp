#include <bits/stdc++.h>
using namespace std;

vector<int> NextGreaterElement(vector<int> & nums){
    int n = nums.size();
    vector<int> nge(n, -1);
    stack<int> st;

    for(int i=2*n-1; i>=0; i--){
        while(!st.empty() && st.top() <= nums[i%n]){
            st.pop();
        }

        if(i<n){
            if(!st.empty()){
                nge[i] = st.top();
            }
        }
        st.push(nums[i%n]);
    }

    return nge;
}


int main(){
    vector<int> nums = {2, 10, 12, 1, 11};
    vector<int> ans = NextGreaterElement(nums);
    for(auto i: ans){
        cout << i << " " ;
    }
    return 0;
}