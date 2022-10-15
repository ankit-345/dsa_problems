#include <iostream>
using namespace std;

int friendspairing(int n){

    if(n==0 || n==1 || n==2){
        return n;
    }

    return friendspairing(n-1) + friendspairing(n-2)*(n-1);  // First (n-1) is for the single and (n=2) is for the couples and we have multiplied it by (n-1) because we need (n-1) to form a couple
}



int main(){

   cout<<friendspairing(4);

    return 0;
}