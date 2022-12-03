#include <iostream>
using namespace std;

bool ispowerof2(int n){
    return (n && !(n & n-1));  // single n is when n is 0 and when we cannot find n-1, then it will return false 
}

int main(){

    cout << ispowerof2(32) << endl;
    return 0;
}