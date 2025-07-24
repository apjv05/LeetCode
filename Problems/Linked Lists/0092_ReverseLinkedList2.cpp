ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head || left == right) return head;

    ListNode* dummy = new ListNode(0, head);
    ListNode* prev = dummy;
    for (int i = 1; i < left; i++) prev = prev->next;

    ListNode* curr = prev->next;
    ListNode* next = nullptr;
    ListNode* tail = curr;

    for (int i = 0; i < right - left + 1; i++) {
        next = curr->next;
        curr->next = prev->next;
        prev->next = curr;
        curr = next;
    }

    tail->next = curr;
    return dummy->next;
}