#include <iostream>

using namespace std;

int computeXOR(int n){

    if(n % 4 == 0)       // if n is multiple of 4 
      return n;
    
    else if(n % 4 == 1)  // if it gives remainder 1
      return 1;

    else if(n % 4 == 2)  // if it gives remainder 2
      return n+1;

    else                 // if it gives remainder 3
      return 0;
}

int main(){
    cout << computeXOR(6);
    return 0;
}