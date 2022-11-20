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

node* reverse_k_groupLL(node* &head, int k){
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
        head->next = reverse_k_groupLL(nextptr, k);
    }

    return prevptr;
}

 node* reverse_group(node* head, int k){
    if(head == NULL || k == 1){
        return head;
    }
    node *dummy = new node(0);
    dummy->next = head;
    node *pre = dummy, *curr = dummy, *nex = dummy;

    int count = 0;
    while(curr->next != NULL){
        curr = curr->next;
        count++;
    }

    while(count >= k){
        curr = pre->next;
        nex = curr->next;

        for(int i=1; i<k; i++){
            curr->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = curr->next;
        }
        pre = curr;
        count -= k;
    }
    return dummy;
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
    display(head);

    head = reverse_k_groupLL(head, 3);
    display(head);
    
    head = reverse_group(head, 3);
    display(head);

    return 0;
}
