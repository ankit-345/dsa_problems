#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){

    string s="faljsflasjfla";
   
    // Function to transform into uppercase
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout << s << endl;

    //Function to transform into lowercase
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    cout << s << endl;
    return 0;
}