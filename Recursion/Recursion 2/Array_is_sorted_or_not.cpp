#include <iostream>
using namespace std;

bool sorted(int arr[], int n){

   if(n==1){     // it is 1 because the array of size 1 is already sorted.
       return true;
   }

   bool restArr = sorted(arr+1, n-1);
   return (arr[0]<arr[1] && restArr);
}

int main(){

    int arr[]={1,2,6,4,5};
    cout<<sorted(arr,5)<<endl;
    return 0;
}