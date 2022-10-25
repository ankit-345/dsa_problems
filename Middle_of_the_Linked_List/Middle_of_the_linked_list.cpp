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

// --------------------------------------------------------------------------------------------------------------->

// Approach 1:
 
int Length(node* head){
    int l=0;                        // 1) count the total number of nodes
    node* temp = head;              // 2) divide by 2 => (N/2) and then increment by 1.
    while(temp != NULL){            // Then simply return the node.
        temp = temp->next;
        l++;
    }
    return l;
}

int middleLL(node* head){
    node* temp = head;
    int l = Length(head);
    l = l/2;
    l++;
    int count = 1;
    while(temp->next != NULL && count != l){
        temp = temp->next;
        count++;
    }
    return temp->data;
}


// Approach 2: (Hare and tortoise method)

int middleofLL(node* head){
    node* slow = head;
    node* fast = head;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}




// --------------------------------------------------------------------------------------------------------------->


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
    display(head);

    // int mid = middleLL(head);
    // cout << mid;

    int middle = middleofLL(head);
    cout << middle;

    return 0;
}