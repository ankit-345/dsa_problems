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

// -------------------------------------------------------------------------------
// ROTATE OF A LINKED LIST

// BRUTE FORCE:

node* rotate(node* head, int k){
    if(head == NULL || head->next == NULL){
        return head;
    }

    for(int i=0; i<k; i++){
        node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        node* end = temp->next;
        temp->next = NULL;
        end->next = head;
        head = end;
    }
    return head;
}


// It is for the right rotation and to do the same for the left rotation, just add the reverse function at the starting and ending of rotate function.

// OPTIMAL APPROACH:

node* rotate_ll(node* head, int k){
    if(head == NULL || head->next == NULL || k == 0){
        return head;
    }

    node* temp = head;

    // Calculate the length of the linked list
    int count = 1;
    while(temp->next != NULL){
        temp = temp->next;
        count++;
    }

    // connect the last node of the linked list to the first node
    temp->next = head;

    // to counter the case, when k > count;
    k = k % count;  

    k = count - k;

    // reach the node from where we have to break the list
    while(k--){
        temp = temp->next;
    }
    
    // storing the 4th in 1->2->3->4->5->NULL list to head.
    head = temp->next;  

    // and pointing 3 to null;
    temp->next = NULL;

   return head;
}




// -------------------------------------------------------------------------------


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
    insertionTail(head, 2);
    insertionTail(head, 4);
    insertionTail(head, 7);
    insertionTail(head, 8);
    insertionTail(head, 9);
    display(head);

    // head = rotate(head, 2);
    // display(head);

    head = rotate_ll(head, 3);
    display(head);

    return 0;
}