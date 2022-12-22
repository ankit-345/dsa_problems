#include <bits/stdc++.h>
using namespace std;

class node{
    public:
       int data;
       node* next;

       node(int val){
        data = val;
        next = NULL;
       }
};

class Stack{
   node* top;
   int size;
   public: 
      Stack(){
        top = NULL;
        size = 0;
      }

      void push(int x){
        node* n = new node(x);
        n->next = top;
        top = n;
        size++;
      }

      int pop(){
        if(top == NULL){
            cout << "Stack is empty" << endl;
            return -1;
        }
        int nodeData = top->data;
        node* temp = top;
        top = top->next;
        delete temp;
        return nodeData;
      }

      int peek(){
        if(top == NULL){
            cout << "Stack is empty" << endl;
            return -1;
        }

        return top->data;
      }

      int Size(){
        return size;
      }

      bool empty(){
        return top == NULL;
      }

      void print(){
        node* temp = top;
        while(temp != NULL){
            cout << temp->data << endl;
            temp = temp->next;
        }
      }
};


int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    s.print();

    cout << s.peek() << endl;

    s.pop();

    cout << s.peek() << endl;

    return 0;
}