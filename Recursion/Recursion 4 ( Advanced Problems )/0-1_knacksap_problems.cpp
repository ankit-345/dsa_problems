#include <iostream>
using namespace std;

int knapsack(int value[], int wt[], int n, int W)  // n = no of items and W = total capacity 
{   
    if(n==0 || W==0){  // Either the items are finish or the Capcity is full
        return 0;
    }

    if(wt[n-1] > W){  // if the weight of an item is greater than the capacity of the Knapsack
        return knapsack(value, wt, n-1, W);   // Then we shall not add that item in the Knapsack,   In this case, we are not adding any item
    }


    return max(knapsack(value, wt, n-1, W-wt[n-1]) + value[n-1], knapsack(value, wt, n-1, W)); // n-1 is there because it starts from zero and In this case, we are adding an item
    
}


int main(){

    int value[] = { 100, 50, 150};
    int wt[] = { 10, 20, 30};
    int W = 50;

    cout<< knapsack(value, wt, 3, W)<< endl;
    return 0;
}






  