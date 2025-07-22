Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> map;
    map[nullptr] = nullptr;

    //create a copy of each node
    Node* cur = head;
    while(cur != nullptr) {
        Node* copy = new Node(cur->val);
        map[cur] = copy;
        cur = cur->next;
    }

    //point each node to where it needs to go
    cur = head;
    while(cur != nullptr) {
        Node* copy = map[cur];
        copy->next = map[cur->next];
        copy->random = map[cur->random];
        cur = cur->next;
    }
    return map[head];
}