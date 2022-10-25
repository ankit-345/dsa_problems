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



// ----------------------------------------------------------------------------------------------------------->
// Approach 1:

int length(node* head){
    int l=0;
    node* temp = head;
    while(temp != NULL){
        l++;
        temp = temp->next;
    }
    return l;
}

void removeNthNode(node* &head, int pos){
    node* temp = head;
    node* todelete;
    int l = length(head);
    int n = l-pos;
    int count = 1;
    if(n == 0){                      // means the first element is to be deleted, since n = l-p => n = 6 - 0 => n == l.
       todelete = head;
       head = head->next;
       delete todelete; 
    }
   else{
    while(temp != NULL && count<n ){
        temp = temp->next;
        count++;
    }

    todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
   }
}


// Approach 2: (Optimised)

node* remove_Nth_Node(node* head, int pos){
    node* start = new node(-1);
    start->next = head;
    node* fast = start;
    node* slow = start;
    
    if((pos-1) == 0){
       return head->next;
    }

    for(int i=0; i<pos; i++){   
        fast = fast->next;
    }

    while(fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return start->next;
}


// ----------------------------------------------------------------------------------------------------------->
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
    insertionTail(head, 1);
    insertionTail(head, 3);
    insertionTail(head, 5);
    insertionTail(head, 6);
    // display(head);

    // removeNthNode(head, 2);
    // display(head);

    head = remove_Nth_Node(head, 2);
    display(head);
    
    return 0;
}