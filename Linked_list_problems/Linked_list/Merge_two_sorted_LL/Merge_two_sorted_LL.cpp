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

// ------------------------------------------------------------------------------------------------------------>

// ITERATIVE METHOD :-

node* merge(node* &head1, node* &head2){   // same as the merging function of the mergeSort.
    node* p1 = head1;
    node* p2 = head2;
    node* dummynode = new node(-1);
    node* p3 = dummynode;

    while(p1 != NULL && p2 != NULL){
        if(p1->data < p2->data){
            p3->next = p1;
            p1 = p1->next;
        }
        else{
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }

    while(p1 != NULL){
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }

    while(p2 != NULL){
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    return dummynode->next;
}


// RECURSIVE METHOD :-

node* mergeRecursive(node* &head1, node* &head2){
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    
    node* result;
    if(head1->data < head2->data){
        result = head1;
        result->next = mergeRecursive(head1->next, head2);
    }
    else{
        result = head2;
        result->next = mergeRecursive(head1, head2->next);
    }
    return result;
}

// ------------------------------------------------------------------------------------------------------------>
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
    node *head1 = NULL;
    insertionTail(head1, 1);
    insertionTail(head1, 4);
    insertionTail(head1, 5);
    insertionTail(head1, 7);
    display(head1);

    node* head2 = NULL;
    insertionTail(head2, 2);
    insertionTail(head2, 3);
    insertionTail(head2, 6);
    display(head2);

    node* head = mergeRecursive(head1, head2);
    display(head);
    return 0;
}