#include <bits/stdc++.h>

using namespace std;

int main(){

    int A[3][3]={{1 , 2, 3}, {4, 5, 6}, {7, 8, 9} };

    for(int i=0; i<3; i++){
        for(int j=i; j<3; j++){     // because we are only accessing the upper part of the 
                                    //matrix
            int temp = A[i][j];     // swapping of the upper part of the matrix with the 
            A[i][j] = A[j][i];      // lower part of the matrix
            A[j][i] = temp;
        }
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}