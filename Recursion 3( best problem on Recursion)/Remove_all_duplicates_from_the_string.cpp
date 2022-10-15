#include <iostream>
using namespace std;

string removeDup(string s){

    if(s.length()==0){
        return "";        // return empty string (Base Case)
    }

    char ch=s[0];
    string ans = removeDup(s.substr(1));

    if(ch==ans[0]){
        return ans;
    }

    return ch+ans;
}



int main(){

   cout<<removeDup("aaaabbbcccceeeeddd")<<endl;
    return 0;
}