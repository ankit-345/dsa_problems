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

// ------------------------------------------------------------------------------------------------------------->

void evenAfterOdd(node* &head){
    node* odd = head;
    node* even = odd->next;
    node* evenStart = even;

    while(odd->next != NULL && even->next != NULL){
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenStart;
    if(odd->next != NULL){   // If last odd_node point to NULL then we need to point last even_node to NULL 
        even->next = NULL;   // otherwise it will run infinitely bcz we have placed last odd->next = evenStart
    }
}



// ------------------------------------------------------------------------------------------------------------->


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

    evenAfterOdd(head);
    display(head);
    return 0;
}