ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy(0);
    ListNode* node = &dummy;

    while(list1 != nullptr && list2 != nullptr) {
        if(list1->val < list2->val) {
            node->next = list1;
            list1 = list1->next;
        }
        else {
            node->next = list2;
            list2 = list2->next;
        }
        node = node->next;
    }

    if(list1 != nullptr) node->next = list1;
    else node->next = list2;

    return dummy.next;
}