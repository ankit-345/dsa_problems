#include <iostream>
using namespace std;

string moveallx(string s){

    if(s.length()==0){
        return "";
    }

    char ch=s[0];  //intial character of the string
    string ans = moveallx(s.substr(1));  // this is not rest of the string

    if(ch=='x'){   //comparing the intial character with the string
        return ans+ch;   // returning the rest of the string followed by character
    }
    return ch+ans;  // returning the character followed by the rest of the string
}



int main(){

    cout<<moveallx("aaxxb")<<endl;

    return 0;
}


