#include <iostream>

using namespace std;                 // 1<<0 = 0001
int getBit(int n, int pos){          // 1<<1 = 0010
    return ((n & (1<<pos))!=0);      // 1<<2 = 0100 
}


int setBit(int n, int pos){
    return (n | (1<<pos));
}

int clearBit(int n, int pos){
    int mask = ~(1<<pos);
    return (n & mask);
}

int updateBit(int n, int pos, int value){
    int mask = ~(1<<pos);
    n = n & mask;
    return (n | (value<<pos));
}

int main(){
    cout << getBit(5,2); 
    // cout << setBit(5,1);
    // cout << clearBit(5,2);    
    // cout << updateBit(5,1,1); 
    return 0;
}