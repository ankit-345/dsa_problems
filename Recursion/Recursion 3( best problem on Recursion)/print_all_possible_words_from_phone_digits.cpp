#include <iostream>
using namespace std;

string keypadArr[]={"","","abc","def","ghi","jkl","mno","pqrs","uvw","xyz"};

void keypad(string s, string ans){

    if(s.length()==0){
        cout<<ans<<"\n";
        return;
    }
    
    char ch=s[0];
    string code = keypadArr[ch-'0'] ; // ch-'0' means that ASCII code of ch - ASCII code of 0 and we need to get the string belong to a particular array
    string ros=s.substr(1);

    for(int i=0; i<code.length(); i++){
        keypad(ros, ans + code[i]);
    }
}

int main(){

    keypad("23", "");
    return 0;
}