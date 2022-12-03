node* mergeTwoLists(node* a, node* b){
	node* temp = new node(0);
	node *res = temp;

	while(a != NULL && b != NULL){
		if(a->data != NULL){
			temp->bottom = a;
			temp = temp->bottom;
			a = a->bottom;
		}
		else{
			temp->bottom = b;
			temp = temp->bottom;
			b = b->bottom
		}
	}

	if(a){
		temp->bottom = a; 
	}

	else{
		temp->bottom = b;
	}
	return res->bottom;
}


node *flatten(node *root){
	if(root == NULL || root->next == NULL){
		return root;
	}
	root->next = flatten(root->next);
	root = mergeTwoLists(root, root->next);
	return root;
}