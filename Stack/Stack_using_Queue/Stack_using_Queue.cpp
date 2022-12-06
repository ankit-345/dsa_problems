#include <bits/stdc++.h>
using namespace std;

class Stack{
    queue<int> q;
    public:
         void Push(int x){
             int s = q.size();
             q.push(x);
             for(int i=0; i<s; i++){
                q.push(q.front());
                q.pop();
             }  
         }


         int Pop(){
            int n = q.front();
            q.pop();
            return n;
         }

         int Top(){
            return q.front();
         }

         int Size(){
            return q.size();
         }

         void display(){
            while(!Size()){
                cout << Top() << endl;
                Pop();
            }
         }
};

int main(){
    Stack s;
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);

    cout << s.Top() << endl;
    s.Pop();
    cout << s.Top() << endl;
    cout << s.Size() << endl;
    s.display();
    return 0;   
}