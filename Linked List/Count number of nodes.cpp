int getCount(struct Node* head) {
    // write code here
    
    if(head == NULL) return 0;
    else if(head -> next == NULL) return 1;
    
    int count = 1;
    struct Node* slow = head;
    struct Node* fast = head -> next;
    
    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
        count++;
    }
    
    if(fast == NULL) return 2*count-1;
    
    return 2*count;
}
