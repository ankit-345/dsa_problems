#include <iostream>

using namespace std;

void swap(int a, int b){

    a ^= b;
    b ^= a;
    a ^= b;

   cout << a << b;
}

int main(){

    swap(2,3);
    return 0;
}