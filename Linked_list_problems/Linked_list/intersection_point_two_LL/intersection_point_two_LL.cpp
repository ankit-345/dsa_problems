
// ----------------------------------------------------------------------------------------------->

// Approach 1;

int length(node* head){
    int l=0;
    node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        l++;
    }
    return l;
}

int intersection(node* head1, node* head2){
  int l1 = length(head1);
  int l2 = length(head2);

  int d = 0;
  node *ptr1, *ptr2;
  if(l1 > l2){
    d = l1-l2;
    ptr1 = head1;
    ptr2 = head2;
  }
  else{
    d = l2 - l1;
    ptr1 = head2;
    ptr2 = head1;
  }

  while(d){
    ptr1 = ptr1->next;
    if(ptr1 != NULL){
        return -1;
    }
    d--;
  }

  while(ptr1 != NULL && ptr2 != NULL){
    if(ptr1 == ptr2){
        return ptr1->data;
    }
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }
  return -1;
}

// Approach 2;

Node getIntersectionNode(node* head1, node* head2){
    if(head1 == NULL || head2 == NULL){
        return NULL;
    }

    Node* a = head1;
    Node* b = head2;

    while(a != b){
        a = a == NULL ? head2: a->next;
        b = b == NULL ? head1: b->next;
    }
    return a;
}

// ----------------------------------------------------------------------------------------------->


