#include <bits/stdc++.h>
using namespace std;

class Queue{
     int *arr;
     int front;
     int back;
     int n = 100;
     public: 
         Queue(){
            arr = new int[n];
            front = -1;
            back = -1;
         }

    void enqueue(int x){
        if(back == n-1){
            cout << "Queue Overflow" << endl;
            return;
        }
        
        back++;
        arr[back] = x;
        if(front == -1){   // Only while adding first element.
            front++;
        }
    }

    void dequeue(){
        if(front == -1 || front > back){
            cout << "Queue empty" << endl;
            return;
        }

        int ele = arr[front];
        front++;
        // cout << "element deleted" << ele << endl;
    }

    int peek(){
        if(front == -1 || front > back){
            cout << "Queue empty" << endl;
            return -1;
        }

        return arr[front];
    }

    bool empty(){
       if(front == -1 || front > back){
          return true;
       }

       return false;
    }
};


int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    while(!q.empty()){
        cout << q.peek() << endl;
        q.dequeue();
    }
}