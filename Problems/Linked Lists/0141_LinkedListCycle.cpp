//optimal solution
bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;

        if(slow == fast) return true;
    }
    return false;
}

//hash set solution
bool hasCycle(ListNode* head) {
    unordered_set<int> nodes;
    ListNode* cur = head;

    while(cur != nullptr) {
        if(nodes.find(cur->val) != nodes.end()) return true;
        nodes.insert(cur->val);
        cur = cur->next;
    }
    return false;
}