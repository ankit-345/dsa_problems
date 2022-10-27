#include <bits/stdc++.h>
using namespace std;

void inverted_pattern_numbers(int n){

// 1 2 3 4 5 
// 1 2 3 4   
// 1 2 3     
// 1 2       
// 1
   for(int i=1; i<=n; i++){
    for(int j=1; j<=n-i+1; j++){
        cout << j << " ";
    }
    cout << endl;
   }
}

void zero_one_pattern(int n){

// 1
// 0 1
// 1 0 1
// 0 1 0 1
// 1 0 1 0 1

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            if((i+j)%2 == 0){             // row+column => even => print 1
                cout << "1" << " ";       // row+column => odd => print 0
            }
            else{
                cout << "0" << " ";
            }
        }
        cout << endl;
    }
}

void rhombus_pattern(int n){
//         * * * * * 
//       * * * * *
//     * * * * *
//   * * * * *
// * * * * *

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            cout << " " << " ";
        }
        for(int j=1; j<=n; j++){
            cout << "*" << " ";
        }
        cout << endl;
    }
}


void numbers_triangle(int n){

//     1
//    1 2
//   1 2 3
//  1 2 3 4
// 1 2 3 4 5
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            cout << " ";
        }
        for(int j=1; j<=i; j++){
            cout << j << " ";         // if the space is not there, it will become like this.
        }                             //     1
        cout << endl;                 //    12
    }                                 //   123, which we don't want.
}

void palidrome_triangle(int n){

//         1 
//       2 1 2
//     3 2 1 2 3
//   4 3 2 1 2 3 4
// 5 4 3 2 1 2 3 4 5
                                     // Column:
  for(int i=1; i<=n; i++){           // => 1 to n-Row
    int j;                           // => " "
    for(j=1; j<=n-i; j++){
        cout << " " << " ";
    }

    int k = i;                       // =>  k = Row_no.
    for(; j<=n; j++){                // =>  k--
       cout << k-- << " ";           // =>  n-Row to n
    }
    
    k = 2;                           // k=2
    for(; j<=n+i-1; j++){            // k++
        cout << k++ << " ";          // n to n + Row - 1
    }
    cout << endl;
  }
}


void star_pattern(int n){

//         * 
//       * * *
//     * * * * *
//   * * * * * * *
// * * * * * * * * *
// * * * * * * * * * 
//   * * * * * * *
//     * * * * *
//       * * *
//         *

    // upper part
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            cout << " " << " ";
        }

        for(int j=1; j<=2*i -1; j++){
            cout << "*" << " ";
        }
        cout << endl;
    }


    // lower part
    for(int i=n; i>=1; i--){
        for(int j=1; j<=n-i; j++){
            cout << " " << " ";
        }

        for(int j=1; j<=2*i -1; j++){
            cout << "*" << " ";
        }
        cout << endl;
    }
}


void zig_zag_pattern(int n){

//     *       *
//   *   *   *   *
// *       *       *
    for(int i=1; i<=3; i++){
        for(int j=1; j<=n; j++){
            if((i+j) % 4 == 0 || (i==2 && j%4 == 0)){
                cout << "*" << " ";
            }
            else{
                cout << " " << " ";
            }
        }
        cout << endl;
    }
}

int main(){
    int n=5;
    inverted_pattern_numbers(n);
    zero_one_pattern(n);
    rhombus_pattern(n);
    numbers_triangle(n);
    palidrome_triangle(n);
    star_pattern(n);
    zig_zag_pattern(9);
    return 0;
}