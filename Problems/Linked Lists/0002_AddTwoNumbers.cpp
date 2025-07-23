ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode();
    ListNode* cur = dummy;

    int carry = 0;
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int v1 = 0, v2 = 0;
        if(l1 != nullptr) v1 = l1->val;
        if(l2 != nullptr) v2 = l2->val;

        int val = v1 + v2 + carry;
        carry = val / 10;
        val = val % 10;
        cur->next = new ListNode(val);

        cur = cur->next;
        if(l1 != nullptr) l1 = l1->next;
        if(l2 != nullptr) l2 = l2->next;
    }
    return dummy->next;
}