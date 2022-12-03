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

// ---------------------------------------------------------------------------------------------->
// REVERSE THE LINKED LIST (ITERATION METHOD)

node *reverseLL(node *&head)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;

    while (currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}

// REVERSE THE LINKED LIST (RECURSIVE METHOD)

node* reverseLLR(node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }
        node* newhead = reverseLLR(head->next);   // newhead will store new node head which will be returned
        head->next->next = head;                  // as a head.
        head->next = NULL;
        return newhead;
}

// ---------------------------------------------------------------------------------------------->
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
    display(head);
    // head = reverseLL(head);
    head = reverseLLR(head);
    display(head);

    return 0;
}