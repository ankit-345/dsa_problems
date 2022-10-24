#include <iostream>
#include <stdio.h>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Repeatedly finding the minimum element from the unsorted part and putting it at the beginning.
// T.C = O(n);
// S.C = O(1);

void selectionSort(int arr[], int n){
    int i, j, min_idx;
    for(int i=0; i<n-1; i++){
        min_idx = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        if(min_idx != i){
            swap(&arr[i], &arr[min_idx]);
        }
    }
}

int main(){
    int arr[] = {5, 2, 3, 1, 7};
    selectionSort(arr, 5);
    for(int i=0; i<5; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}