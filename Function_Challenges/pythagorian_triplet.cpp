# include <bits/stdc++.h>
using namespace std;
bool check(int x, int y, int z){

    int a= max(x, max(y,z));
    int b,c;

    if (a==x)
    {
        b=y;
        c=z;
    }
    else if (a==y)
    {
        b=x;
        c=z;
    }
    else if (a==z)
    {
        b=x;
        c=y;
    }

    if(a*a==b*b + c*c)
      return true;
    else
      return false;
}

int main()
{
    int x,y,z;
    cout<< "Enter the three Numbers(x,y,z): ";
    cin >> x >> y >> z;
    if(check(x,y,z))
      cout<<"Pythagorian triplet exist";
    else
      cout<<"Pythagorian triplet does not exist";
      
    return 0;
}
