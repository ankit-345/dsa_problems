#include <iostream>
#include <string>
using namespace std;

string subseq(string s, string ans = ""){

    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }

    char ch=s[0];
    int code = ch;
    string ros = s.substr(1);

    subseq(ros, ans);
    subseq(ros, ans+ ch);
    subseq(ros, ans + to_string(code));  // to_string convert the integer into a string
}

int main(){

    subseq("AB", "");
    cout<<endl;
    return 0;
}