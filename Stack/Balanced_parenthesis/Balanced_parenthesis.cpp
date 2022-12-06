#include <bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s){
    stack<char> st;
    for(auto it: s){
      if(it == '(' || it == '{' || it == '['){    // on encountering open brackets, push it into the stack
          st.push(it);
      }
      
      else{                                      // on encountering close brackets, check whether the stack is empty, 
        if(st.size() == 0){
            return false;                        // If it is, then return false
        }

        char ch = st.top();                      // if not empty, then check whether the close bracket matches the top element (open bracket) of the stack.
        st.pop();                                // don't forget to pop the stack afterwards so as to check the next closing bracket.
        if((it == ')' && ch == '(') || (it == '}' && ch == '{') || (it == ']' && ch == '[')){
            continue;
        }
        else{
            return false;
        }
      }
    }
    return st.empty();    // if the string is valid, then no elements will remain after the execution,
                          // if an element remains after the execution, that means string is inValid.
}


int main(){
    string s = "{}";
    cout << isValid(s) << endl;
    return 0;
}