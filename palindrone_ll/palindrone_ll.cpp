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

// ------------------------------------------------------------------------------------------>

node* Reverse(node* head){
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    while(currptr != NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }

    return prevptr;
}


bool isPalindrone(node *head){
    if(head == NULL || head->next == NULL){
        return true;
    }
    
    node* fast = head;
    node* slow = head;
    while(fast->next != NULL && fast->next->next != NULL){
       slow = slow->next;
       fast = fast->next->next;
    }
    slow->next = Reverse(slow->next);
    slow = slow->next;
    
    node* temp = head;
    while(slow != NULL){
        if(temp->data != slow->data){
            return false;
        }
        temp = temp->next;
        slow = slow->next;
    }
    return true;
}




// ------------------------------------------------------------------------------------------>

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
    insertionTail(head, 3);
    insertionTail(head, 2);
    insertionTail(head, 1);
    // display(head);

    cout << isPalindrone(head) << endl;
    // display(head);
    

    return 0;
}