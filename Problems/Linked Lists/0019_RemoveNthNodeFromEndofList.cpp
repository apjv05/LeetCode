//two pass solution
ListNode* removeNthFromEnd(ListNode* head, int n) {
    int ListSize = 0;
    ListNode* cur = head;
    while(cur != nullptr) {
        ListSize++;
        cur = cur->next;
    }

    int DeletedNode = ListSize - n;
    if(DeletedNode == 0) return head->next;

    cur = head;
    for(int i = 0; i < ListSize - 1; i++) {
        if(i + 1 == DeletedNode) {
            ListNode* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
            break;
        }
        cur = cur->next;
    }
    return head;
}

//one pass solution
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0,head);
    ListNode* first = head;
    ListNode* second = dummy;

    for(int i = 0; i < n; i++) first = first->next;
    while(first != nullptr) {
        first = first->next;
        second = second->next;
    }

    ListNode* temp = second->next;
    second->next = second->next->next;
    delete temp;
    return dummy->next;
}