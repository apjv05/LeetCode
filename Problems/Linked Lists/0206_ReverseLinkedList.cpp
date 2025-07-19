ListNode* reverseList(ListNode* head) {
    ListNode* cur = head;
    ListNode* prev = nullptr;

    while(cur != nullptr) {
        ListNode* next_tmp = cur->next;

        cur->next = prev;
        prev = cur;
        cur = next_tmp;
    }
    return prev;
}