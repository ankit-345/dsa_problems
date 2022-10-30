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


// ------------------------------------------------------------------------------------------------->

node* addTwoNumbers(node* head1,node* head2){
   node *dummy = new node(-1);
   node *temp = dummy;
   int carry = 0;
   while(head1 != NULL || head2 != NULL || carry){
    int sum = 0;
    if(head1 != NULL){              
        sum += head1->data;         
        head1 = head1->next;
    }

    if(head2 != NULL){            
        sum += head2->data;      
        head2 = head2->next;
    }
    sum += carry;                  
    carry = sum/10;

    node* n = new node(sum%10);
    temp->next = n;
    temp = temp->next;
   }
   
   return dummy->next;
}




// ------------------------------------------------------------------------------------------------->


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
    insertionTail(head1, 2);
    insertionTail(head1, 4);
    insertionTail(head1, 3);
    display(head1);

    node *head2 = NULL;
    insertionTail(head2, 5);
    insertionTail(head2, 6);
    insertionTail(head2, 7);
    insertionTail(head2, 9);
    display(head2);

    node* head = NULL;
    head = addTwoNumbers(head1, head2);
    display(head);
    return 0;
}