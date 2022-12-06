#include <bits/stdc++.h>
#include <stack>
using namespace std;

void reverse_sentence(string s){
    stack<string> st;

    for(int i=0; i<s.length(); i++){
        string words = "";
        while(s[i] != ' ' && i<s.length()){  // when a space is encountered, we push the word into the stack;
            words += s[i];
            i++;
        }
        st.push(words);
    }

    while(!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }
    cout << " ";
}


int main(){
    string s = "Ankit Maurya";
    reverse_sentence(s);
}