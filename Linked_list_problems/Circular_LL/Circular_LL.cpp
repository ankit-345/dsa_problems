#include<bits/stdc++.h>
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

void insertAtHead(node* &head, int val){
    node* temp = head;
    node* n = new node(val);

    if(head == NULL){
        n->next = n;
        head = n;
        return;
    }

    while(temp->next != head){
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
    head = n;

}

void insertAtTail(node* &head, int val){
    node* temp = head;
    node* n = new node(val);

    if(head == NULL){
        insertAtHead(head, val);
        return;
    }

    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}


void deleteAtHead(node* &head){
    node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    
    node* todelete = head;
    temp->next = head->next;
    head = head->next;
    cout << todelete->data << "is Deleted";
    delete todelete;
}


void deleteAtTail(node* &head, int pos){
    if(pos == 1){
        deleteAtHead(head);
        return;
    }
    
    node* temp = head;
    int count = 1;
    while(count != pos-1){
       temp = temp->next;
       count++;
    }

    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}


void display(node* head){
    node* temp = head;
    do{
        cout << temp->data << "->";
        temp = temp->next;
    }while(temp != NULL);
    cout << "NULL" << endl;
}



int main(){
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    // display(head);
    
    deleteAtTail(head, 2);
    // display(head);
}