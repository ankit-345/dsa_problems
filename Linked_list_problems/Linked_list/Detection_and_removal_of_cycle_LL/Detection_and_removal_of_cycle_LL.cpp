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

// Making a Cycle

void makeCycle(node *&head, int pos)
{
    node *temp = head;
    node *startnode;
    int count = 1;

    while (temp->next != NULL)
    {
        if (count == pos)
        {
            startnode = temp;
        }
        temp = temp->next;
        count++;
    }

    temp->next = startnode;
}

// Detection of Cycle In Linked List

bool detectCycle(node *&head)
{
    node *fast = head;
    node *slow = head;

    while (fast != NULL & fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

// Removal of cycle from the Linked List

void removal(node* &head){
    node* slow = head;
    node* fast = head;

    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(fast != slow);

    fast = head;
    while(fast->next != slow->next){
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL;
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
    insertionTail(head, 5);
    insertionTail(head, 6);
    insertionTail(head, 7);
    insertionTail(head, 8);
    insertionTail(head, 9);
    display(head);

    makeCycle(head, 4);
    cout << detectCycle(head) << endl;
    removal(head);
    cout << detectCycle(head) << endl;
    display(head);

    return 0;
}