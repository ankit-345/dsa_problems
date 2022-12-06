#include <bits/stdc++.h>
using namespace std;

class Stack{
    int* arr;
    int top;
    int n = 100;
    public:
      Stack(){
        arr = new int[n];
        top = -1;
      }

      void push(int x){
        if(top == n-1){
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
      }

      void pop(){
        if(top == -1){
            cout << "Stack empty" << endl;
            return;
        }
        int x = arr[top];
        top--;
        cout << "element deleted" << x << endl;
      }

      int Top(){
        if(top == -1){
            cout << " stack empty " << endl;
            return -1;
        }

        return arr[top];
      }

      bool empty(){
        return top == -1;
      }
};


int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    s.pop();
    s.pop();
   cout << s.empty() << endl;

    // cout << s.Top() << endl;
    return 0;
}