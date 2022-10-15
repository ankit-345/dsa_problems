#include <iostream>
#include <string>
#include <algorithm>  // to use sort function, we need algorithm header file
using namespace std;

int main(){
    
  string str = "jflskdfslkfslkfjlskfjsl";

  sort(str.begin(), str.end());

  cout << str << endl;

  return 0;
}