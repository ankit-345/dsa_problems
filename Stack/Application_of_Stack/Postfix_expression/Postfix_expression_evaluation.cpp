#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int postfixEvaluation(string s){
    stack<int> st;                              // The difference b/w prefix_evaluation and postfix_evaluation is that
    for(int i=0; i<s.length(); i++){            // 1) prefix evaluation starts from end whereas postfix evaluation 
        if(s[i] >= '0' && s[i] <= '9'){         //    starts from beginning.
            st.push(s[i] - '0');
        }
        else{
            int op2 = st.top();                 // 2) In prefix, 1st operand(operand at top) goes to op1(variable) 
            st.pop();                           //    and 2nd operand(next operand at top) goes to op2(variable)
            int op1 = st.top();
            st.pop();                           //    But in postfix, It is the opposite, 1st operand = op2 and 2nd operand = op1

            switch(s[i]){
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
                default: cout << "Wrong option";
                       break;
            }
        }
    }
   return st.top();
}



int main(){
    string s= "46+2/5*7+";
    int ans = postfixEvaluation(s);
    cout << ans;
    return 0;
}