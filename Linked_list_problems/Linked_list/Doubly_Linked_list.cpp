#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node *prev;
    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};



void insertionAtHead(node* &head, int val){
    node *n = new node(val);
    
    n->next = head;
    if(head != NULL){
        head->prev = n;
    }
    head = n;
}




void insertionAtTail(node* &head, int val){

    if(head == NULL){
        insertionAtHead(head, val);
        return;
    }
    node *n = new node(val);
    node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next =  n;
    n->prev = temp;
}



void deletionatHead(node* &head){
    node* todelete = head;
    head = head->next;
    head->prev = NULL;

    delete todelete;
}



void deletion(node* &head, int pos){
    node* temp = head;
    int count = 1;

    while(temp!=NULL && count!=pos){
        temp = temp->next;
        count++;
    }

    temp->prev->next = temp->next;
    if(temp->next != NULL){
         temp->next->prev = temp->prev;
    }

    delete temp;
}


// APPEND LAST K-NODE TO THE START OF THE LINKED LIST

int length(node *head){
    node* temp = head;
    int l = 0;

    while(temp != NULL){
        l++;
        temp = temp->next;
    }
    return l;
}


node* kappend(node* &head, int k){

    node* newhead;
    node* newtail;
    node* tail = head;

    int l=length(head);
    int count = 1;
    k = k % l;

    while(tail->next != NULL){
        if(count == l-k){
            newtail = tail;
        }
        if(count == l-k+1){
            newhead = tail;
        }
        count++;
        tail = tail->next;
    }

    newtail->next = NULL;
    tail->next = head;

    return newhead;
}




void display(node *head){
    node *temp = head;

    while(temp != NULL){
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}



int main(){
    
    node *head = NULL;
    insertionAtTail(head, 1);
    insertionAtTail(head, 2);
    insertionAtTail(head, 3);
    insertionAtTail(head, 4);
    insertionAtTail(head, 5);
    insertionAtTail(head, 6);
    display(head);

    node *newhead2 = kappend(head, 3);
    display(newhead2); 
    return 0;
}