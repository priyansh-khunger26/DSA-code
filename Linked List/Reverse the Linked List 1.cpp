Node *reverseLinkedList(Node *head) {
    if(head == NULL || head -> next == NULL) {
		return head;
	}

	Node* prev = NULL;
	Node* curr = head;
	Node* nex = head -> next;

	while(nex != NULL) {
		curr -> next = prev;

		prev = curr;
		curr = nex;
		nex = nex -> next;
	}

	curr -> next = prev;

	return curr;
}
