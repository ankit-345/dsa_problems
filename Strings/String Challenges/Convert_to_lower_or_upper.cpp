#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string str="ajfalsfafjaslkfjasf";
    string str1="FJLAFJKALJFASLJFLAJFL";
    // convert the lower string to upper string

    for(int i=0; i<str.size(); i++){
        if(str[i]>='a' && str[i] <= 'z'){
            str[i] -= 32;
        }
    }
    cout << str <<endl;

    for(int i=0; i<str1.size(); i++){
        if(str1[i]>='A' && str1[i] <= 'Z'){
            str1[i] += 32;
        }
    }
    cout << str1;
    
    return 0;
}