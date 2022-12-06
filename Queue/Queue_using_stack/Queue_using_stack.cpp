#include <bits/stdc++.h>
using namespace std;


// APPROACH 1: T.C. = O(N);   S.C. = O(2N)

// class Queue{
//     stack<int> s1, s2;
//     public:
//        void enqueue(int data){
//           // S1 --> S2
//           while(!s1.empty()){
//             s2.push(s1.top());
//             s1.pop();
//           }

//           // add data -> S1
//           s1.push(data);

//           // S2 --> S1
//           while(!s2.empty()){
//             s1.push(s2.top());
//             s2.pop();
//           }
//        }



//        int dequeue(){
//         if(s1.empty()){
//             cout << "Queue is empty";
//             return -1;
//         }

//         int ele = s1.top();
//         s1.pop();
//         return ele;
//        }




//        int peek(){
//         if(s1.empty()){
//             cout << "Queue is empty";
//             return -1;
//         }

//         return s1.top();
//        }


// };


// -------------------------------------------------------------------------------------------------------------

// APPROACH 2: Amortised O(1)

class Queue{
     stack<int> s1, s2;
     public:
         void enqueue(int data){
             s1.push(data);
         }

         int dequeue(){
            // if the s2 is empty, then s1 -> s2
            // if not empty, then simply pop the element and return the element
            if(s1.empty() && s2.empty()){
                return -1;
            }

            if(s2.empty()){

                // S1 --> S2;
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }

            int ele = s2.top();
            s2.pop();
            return ele;
         }

         int peek(){
            if(s1.empty() && s2.empty()){
                return -1;
            }
            // Almost same as dequeue;
            if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }

            return s2.top();
         }
};

// -------------------------------------------------------------------------------------------------------------
int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
}