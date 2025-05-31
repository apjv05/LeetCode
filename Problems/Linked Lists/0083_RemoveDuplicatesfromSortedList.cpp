ListNode* deleteDuplicates(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;

    ListNode* current = head;

    while(current != nullptr && current->next != nullptr) {
        if(current->val == current->next->val) {
            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        else {
            current = current->next;
        }
    }
    return head;
}