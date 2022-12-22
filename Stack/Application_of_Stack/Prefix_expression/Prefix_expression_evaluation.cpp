#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int prefixEvaluation(string s){
    stack<int> st;
    for(int i=s.length() - 1; i>=0; i--){     // if it is operand, then push it into the stack
        if(s[i] >='0' && s[i]<='9'){
            st.push(s[i] - '0');
        }
        else{
            int op1 = st.top();             // if it is operator, then pop 2 operand from the stack
            st.pop();                     
            int op2 = st.top();
            st.pop();
            
            switch (s[i])                   // perform the relevant operation and then push the result
            {                               // back into the stack.
            case '+': st.push(op1 + op2);
                break;
            case '-': st.push(op1 - op2);
                break;
            case '*': st.push(op1 * op2);
                break;
            case '/': st.push(op1 / op2);
                break;
            case '^': st.push(pow(op1, op2));
                break;
            default:
                break;
            }
        }
    }
    return st.top();                         // Then return the last element which is our answer.
}

int main(){
    string s = "-+7*45+20";
    int ans = prefixEvaluation(s);
    cout << ans << endl;
    return 0;
}