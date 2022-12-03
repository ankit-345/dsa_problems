#include <iostream>
using namespace std;

int tillingWays(int n)  // no. of tiles
{
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }

    return tillingWays(n-1) + tillingWays(n-2); // (n-1) is for vertical tilling and (n-2) is for horizontal tilling
}

int main(){

   cout<<tillingWays(4)<<endl;
   return 0;
}