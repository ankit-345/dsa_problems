#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertionTail(node *&head, int val)
{
    node *n = new node(val);
    node *temp = head;
    if (head == NULL)
    {
        head = n;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

// -------------------------------------------------------------------------------------------------------------->
int length(node* head){
    node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

node* kappend(node* &head, int k){
    node* newTail;
    node* newHead;
    node* Tail = head;
    int l = length(head);
    int count = 1; k=k%l;

    while(Tail->next != NULL){
        if(count == l-k){
           newTail = Tail;
        }
        if(count == l-k+1){
            newHead = Tail;
        }
        count++;
        Tail = Tail->next;
    }
    Tail->next = head;
    newTail->next = NULL;

    return newHead;
}
// -------------------------------------------------------------------------------------------------------------->


void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;
    insertionTail(head, 1);
    insertionTail(head, 2);
    insertionTail(head, 3);
    insertionTail(head, 4);
    insertionTail(head, 5);
    insertionTail(head, 6);
    display(head);
    
    head = kappend(head, 3);
    display(head);
    return 0;
}