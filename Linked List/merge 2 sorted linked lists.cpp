ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* dummyTail = dummyHead;
    
    while(head1 != NULL && head2 != NULL) {
        if(head1 -> val < head2 -> val) {
            dummyTail -> next = head1;
            dummyTail = head1;
            head1 = head1 -> next;
        }else{
            dummyTail -> next = head2;
            dummyTail = head2;
            head2 = head2 -> next;
        }
    }

    if(head1 != NULL) dummyTail -> next = head1;
    else if(head2 != NULL) dummyTail -> next = head2;

    return dummyHead -> next;
}
