#include <iostream>
using namespace std;

void reverse(string s){

    if(s.length()==0){
        return;
    }

    string ros = s.substr(1);  // it means that after index 1 , the rest will go to ros
    reverse(ros);
    cout<<s[0];
}

int main(){
    string s;
    cin>>s;
    reverse(s);
    return 0;
}
