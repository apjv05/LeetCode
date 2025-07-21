void reorderList(ListNode* head) {
    //find middle
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    //reverse second half
    ListNode* second = slow->next;
    ListNode* prev = slow->next = nullptr;
    while(second != nullptr) {
        ListNode* temp = second->next;
        second->next = prev;
        prev = second;
        second = temp;
    }

    //merge first & second halfs
    ListNode* first = head;
    second = prev;
    while(second != nullptr) {
        ListNode* temp1 = first->next;
        ListNode* temp2 = second->next;
        
        first->next = second;
        second->next = temp1;
        first = temp1;
        second = temp2;
    }
}