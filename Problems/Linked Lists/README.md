# Linked List Patterns

## Fast and slow pointers
Have one pointer move faster than the other, usually at twice the speed. Used when you need to detect cycles, middle points, or manage traversal without extra memory. Although covered in the Two Pointers Section, fast and slow is much more used when dealing with linked lists than arrays

When to use
- Finding the middle of a linked list
- Detecting cycles
- Finding the Nth node from the end
- Checking Palindromes
- Maintain a fixed or relative distance between two pointers

Key Properties
- One pointer moves once at a time, and the other moves twice at a time
- Maintain a specific relative distance or meet under conditions
- Given enough time, the fast pointer will catch the slow pointer
- Dummy Node technique: putting a dummy node at the beginning of your linked list can simplify edge cases

## Reversing Linked List
iterate through the list, changing the next pointer of each node to point to its previous node. This often involves three pointers: previous, current, and next_temp

When to use
- When asked to
- After finding middle, reversing the second half is a common step
- Processing the list from tail to head efficiently
- k-group reversals or other block-wise manipulations

Key Properties
- Iterative Approach
    - Maintain three pointers: previous (initially null), current (initially head), and next
    - In each iteration
        1. Store your next node in a variable `temp`
        2. Reverse it by setting `current->next = previous`
        3. Move previous forward by `previous = current`
        4. Move current forward by `current = temp`
    - The new `head` of the reversed list will be `previous` after the loop finishes because its reversed
- Recursive Approach
    - Base case: If head is None or head->next is None, return head
    - Recursive step: new_head = reverseList(head->next)
    - Fix current node's pointer: head->next->next = head
    - Set current node's next to None: head->next = None
    - Return new_head

## Dummy Nodes
As  discussed before using a dummy node can simplify edge cases, especially when operations involve modifying the head of the list. It acts as a placeholder, so you don't have to constantly check for null head pointers. Using the dummy node will create a new list that you can do whatever on.

When to Use
- Operations that might modify the head of the list: This is the most common use case. For example, deleting the first node, inserting at the beginning, or merging lists where the new head needs to be determined dynamically
- Simplifying edge cases related to an empty list or operations at the beginning of the list
- When you need a fixed reference point before the actual head that won't change

Key Properties
- Create a dummy node (e.g., ListNode(0)) and point its next to the original head
- Operations on dummy->next: All operations effectively start from dummy->next, so you don't have to write special checks for head == None or head changing
- Return dummy->next: After all operations are complete, the actual head of the modified list will be dummy->next

## Merging Linked Lists
Problems often require merging two (or more) sorted linked lists into a single sorted list. This typically involves iterating through both lists and picking the smaller of the current nodes to append to the new merged list.

When to Use
- Combining two or more sorted linked lists into a single sorted list
- Often a sub-problem in larger linked list problems

Key Properties
- Find the node you need to merge/do logic to validate
- update previous node to point to the merged node
- update the merged node to point to the next of the previous node

## Hash Table
For problems where you need to keep track of visited nodes, or map original nodes to copied nodes (in case of deep copy with random pointers), a hash map can be very useful.

When to Use
- When you need to quickly check if a node has been visited before
- To map original nodes to their corresponding copied nodes, preventing infinite loops and ensuring correct pointer assignment
- Problems where you need to store and retrieve information about nodes that are not directly adjacent

Key Properties
- Use a hash set to store visited nodes or a hash map to store key-value pairs
- O(1) average time complexity for checking presence or retrieving values
- If node in visited_set is True, a cycle exists
- Iterate through the original list, create a new node for each, and store the mapping (original_node : new_node) in the hash map
- Then, iterate again to set the next and random pointers of the new nodes using the map

## Iterative Traversal with a Single Pointer
Many basic linked list operations, like searching for a value, inserting at a specific position (not head/tail), or deleting a specific node, involve a straightforward iterative traversal using a single pointer.

When to Use
- Searching for a value, inserting at a specific position (not head), deleting a specific node (when given the predecessor), printing the list
- When you only need to look at the current node and potentially its immediate successor

Key Properties
- Initialize current = head
- Continue as long as current is not None
- Current = current->next in each iteration
- Often, you'll need a previous pointer to keep track of the node before current to modify links