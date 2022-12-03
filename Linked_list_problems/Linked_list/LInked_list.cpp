#include <iostream>
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

// ---------------------------------------------------------------------------------------------------------------

// Insertion at the beginning of the linked list
void insertathead(node *&head, int val)
{
    node *n = new node(val);
    node *temp = head;
    head = n;
    n->next = temp;
}

// ---------------------------------------------------------------------------------------------------------------

// Insertion at the ending of the linked list
void insertatTail(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
}


// ---------------------------------------------------------------------------------------------------------------

// Searching in the linked list
bool searching(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}


// ---------------------------------------------------------------------------------------------------------------

// Deletion from the beginning of the linked list
void deleteathead(node *&head)
{
    node *todelete = head;
    head = head->next;

    delete todelete;
}

// ---------------------------------------------------------------------------------------------------------------

// Deletion at the particular index of the linked list
void deletion(node *&head, int val)
{
    node *temp = head;

    if (head == NULL)
    {
        return;
    }

    if (head->next == NULL)
    {
        deleteathead(head);
        return;
    }
    while (temp->next->data != val)
    {
        temp = temp->next;
    }

    node *todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

// ---------------------------------------------------------------------------------------------------------------

// Reversing the linked list (iterative method)
node* reverse(node* &head){
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    while(currptr != NULL){
        nextptr= currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }

    return prevptr;
}

// ---------------------------------------------------------------------------------------------------------------

// REVERSING THE LINKED LIST (RECURSIVE METHOD)
node *reverse_recursive(node* &head){


    if(head == NULL || head->next == NULL)  // first condition => for empty, second condition => for single value
    {
        return head;
    }
    node *newhead = reverse_recursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;
}

// ---------------------------------------------------------------------------------------------------------------

// Display the linked list
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

// ---------------------------------------------------------------------------------------------------------------

// REVERSING THE K-NODE IN THE LINKED LIST

node* reverse_k(node* &head, int k){
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    int count = 0;

    while(currptr != NULL && count<k){
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
        count++;
    }
    
    if(nextptr != NULL){
    head->next = reverse_k(nextptr, k);
    
    }

    return prevptr;
}

// ---------------------------------------------------------------------------------------------------------------

// MAKING THE CYCLE IN THE LINKED LIST

void makecycle(node* &head, int pos){
    node* temp = head;
    node* startnode;

    int count = 1;
    while(temp->next != NULL){
        if(count == pos){
            startnode = temp;
        }
        count++;
        temp = temp->next;
    }
    temp->next = startnode;
}

// ---------------------------------------------------------------------------------------------------------------

// DETECTION OF CYCLE IN THE LINKED LIST

bool detectCycle(node* &head){
    node* slow = head;
    node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true;
        }
    }
    return false;
}

// ---------------------------------------------------------------------------------------------------------------

// REMOVAL OF CYCLE IN THE LINKED LIST

void removeCycle(node* &head){
    node* slow = head;
    node* fast = head;

    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(fast != slow);

    fast = head;
    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}

// ---------------------------------------------------------------------------------------------------------------
int main()
{
    node *head = NULL;
    insertatTail(head, 1);
    insertatTail(head, 2);
    insertatTail(head, 3);
    insertatTail(head, 4);
    insertatTail(head, 5);
    insertatTail(head, 6);
    display(head);

    // node* newhead = reverse(head);
    // node* newhead2 = reverse_recursive(head);
    // display(newhead2);
    
    makecycle(head, 3);
    cout << detectCycle(head) << endl;
          
    removeCycle(head);
    cout << detectCycle(head);
    return 0;
}