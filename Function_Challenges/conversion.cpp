# include <bits/stdc++.h>
using namespace std;

// Function for conversion of binary numbers to decimals

// int binarytodecimal(int n){
    
//     int ans=0;
//     int x=1;
//     int y;
//     while (n>0){
//         y=n%10;
//         ans+=x*y;
//         x*=2;
//         n/=10;
//     }
//     return ans;
// }


// Function for conversion of octal numbers to decimals

// int octaltodecimal(int n){
//     int ans=0;
//     int x=1,y;
//     while(n>0){

//         y=n%10;
//         ans+=x*y;
//         x*=8;
//         n/=10;
//     }
//     return ans;
//     }


// int main(){

//     int n;
//     cout << "Enter the number: ";
//     cin>>n;
//     cout<<octaltodecimal(n)<<endl;
//     return 0;
// }


// Function for conversion of hexadecimal to decimals

int hexadecimaltodecimal(string n){

    int ans=0;
    int x=1;
    int s=n.size();

    for(int i=s-1; i>=0; i--){
          if (n[i]>='0' && n[i]<='9')
             ans+=x*(n[i]-'0');
        else if(n[i]>='A' && n[i]<='F')
             ans+=x*(n[i]-'A'+10);
        x*=16;
    }
    return ans;
}


int main(){

    string n;
    cout << "enter the hexadecimal number: ";
    cin>>n;
    cout<<hexadecimaltodecimal(n)<<endl;
    return 0;
}