#include <iostream>
using namespace std;

void subseq(string s, string ans) // ans string is to store the answer
{    
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    string ros = s.substr(1);

    subseq(ros, ans);   // in this we are returning the empty string.
    subseq(ros, ans+ch);  // In this we are returning the rest of string followed by the character
}


int main(){

    subseq("ABC", "");
    cout<<endl; 
    return 0;
}