#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    
    string s="asfjaskfjlfjas";
    int freq[26];

    for(int i=0; i<26; i++){
        freq[i]=0;
    }

    for(int i=0; i<s.size(); i++){
        freq[s[i]-'a']++;
    }

    char ans = 'a';
    int maxf = 0;

    for(int i=0; i<26; i++){
        if(maxf <= freq[i]){
            maxf = freq[i];
            ans = i+'a';
        }
    }

    cout << maxf <<" " << ans;
    return 0;
}