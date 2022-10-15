#include <iostream>
using namespace std;

int setBitNumber(int n){

    n |= n>>1;
    n |= n>>2;
    n |= n>>4;
    n |= n>>8;
    n |= n>>16;

    n = n+1;
    return (n>>1);
}


int main(){

    cout << setBitNumber(5);
    return 0;
}