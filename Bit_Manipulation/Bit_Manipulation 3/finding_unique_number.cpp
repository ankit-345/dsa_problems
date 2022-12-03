// Write a program to find a unique number in a array where all number except one, are present thrice

#include <iostream>
using namespace std;

bool getBit(int n, int pos){
    return (n & (1<<pos))!=0;
}
int setBit(int n, int pos){
    return (n | (1<<pos));
}

int unique(int arr[], int n){
    int result = 0;
    for(int i=0; i<64; i++){   //This loop traverse all the places in the array
        int sum=0;
        for(int j=0; j<n; j++){  //This loop traverse and count the ones at the 
            if(getBit(arr[j], i)){  //position.
               sum++;
            }
        }
    if(sum%3 != 0){         // It set the bit(1) at the position where the 
        result = setBit(result, i);  //module of the sum is not 3.
    }
    }
    return result;    
}

int main(){
    int arr[]={1,2,3,4,1,2,3,1,2,3};
    cout << unique(arr,10) <<endl;
    return 0;
}