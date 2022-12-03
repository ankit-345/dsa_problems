// Write a program to find a unique number in a array where all number except two, are present twice

#include <iostream>
using namespace std;

int setBit(int n, int pos){
    return (n & (1<<pos))!=0;    // checking the setbit(means 1) at pos.
}

void unique(int arr[], int n){

    int xorsum = 0;
    for(int i=0; i<n; i++){      // This Part is finding the two unique number.
        xorsum = xorsum^arr[i];
    }
    
    int tempxor = xorsum;
    int setbit = 0;
    int pos = 0;                 // this part is finding at which position of 
    while(setbit != 1){          // the unique number , There is a set bit.
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum >> 1;
    }

    int newzor = 0;
    for(int i=0; i<n; i++){         // This part is finding one of the two unique 
        if(setBit(arr[i], pos-1)){  // number by implementing the xor of the number 
           newzor = newzor^arr[i];  //(with 1 at the position found above),with the 
        }                           // rest of the number.
    }
    
    cout<< newzor << endl;
    cout<< (tempxor^newzor)<< endl;
}


int main(){
    int arr[]={1,2,3,1,2,3,7,5};
    unique(arr,8);
    return 0;
}