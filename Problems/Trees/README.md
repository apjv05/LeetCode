# Tree Patterns
## Depth-First Search (DFS) - Recursive
Explores as far as possible along each branch before backtracking

When to use
- When the problem involves exploring entire branches before moving to the next
- When the order of visiting nodes within a branch is crucial
- Most common for tree problems because of the natural recursive structure

Key Properties
- Base Case: What happens when you reach a null node? (Often return 0, true, false, or an empty list)
- Recursive Step
    - Process the current node
    - Make recursive calls to node.left and node.right
    - Combine or use the results from the recursive calls to solve for the current node
- Implicit Stack: The call stack handles the "backtracking."

Variants
- Pre-order (Root, Left, Right)
    - When to Use: Problems where you need to process the node before its children.
    - Logic: `process(node)` -> `dfs(node->left)` -> `dfs(node->right)`
- In-order (Left, Root, Right)
    - When to Use: Especially for Binary Search Trees (BSTs), as it visits nodes in ascending order
    - Logic: `dfs(node->left)` -> `process(node)` -> `dfs(node->right)`
- Post-order (Left, Right, Root)
    - When to Use: Problems where you need results from both children before processing the current node
    - Logic: `dfs(node->left)` -> `dfs(node->right)` -> `process(node)`

## Breadth-First Search (BFS) - Iterative with Queue
Explores all nodes at the current depth level before moving to the next depth level.

When to use
- When the problem involves processing nodes level by level
- Finding the shortest path in an unweighted tree (since BFS explores layer by layer, the first time you find the target, it's the shortest path)
- Problems that require knowing the depth or level of nodes

Key Properties
- Use a Queue to store nodes to visit
- Add the root node to the queue
- While the queue is not empty
    - Get the current_level_size (important for processing level by level)
    - Loop current_level_size times
        - de queue a node
        - do logic on node
        - queue its children
- Level Tracking: Often involves a variable to increment the level or depth after each outer loop iteration

## Divide and Conquer
Trees are inherently recursive data structures. Many problems can be elegantly solved by defining a recursive function that operates on a node and then combines results from its children

When to use
- Use when a problem on a node can be solved by combining solutions from its children

Key Properties
- Define what the function solve(node) should return or do for a single node
- Handle null nodes (the stopping condition)
- Call solve(node.left) and solve(node.right)
- Use the results from the children to compute the result for the current node
- Top-Down
    - Pass information down from parent to children via function arguments
    - Use when: Information from ancestors is needed to make decisions or accumulate results for descendants
- Bottom-Up
    - Return information up from children to parents
    - Information about descendants is needed to compute a result for the current node

## Binary Search Tree

When to use
- When the problem explicitly states it's a BST, or you need to leverage its sorted property

Key Properties
- In-order Traversal is Sorted: The fundamental property
- For searching, insert, delete: If `target < node->val`, go left; if `target > node->val`, go right
- Efficiently find all nodes within a given range [low, high] by pruning branches outside the range
- Successor/Predecessor: Finding the next/previous node in sorted order

## Parent Pointers / Storing Parent References
Some problems might require knowing the parent of a node, which isn't directly available in a standard tree node definition. You might need to build a map during traversal to store parent references.

When to use
- When a problem requires navigating up the tree, or needs to know the parent of a node. Standard tree nodes usually only have left and right child pointers.

Key Properties
- During a traversal (DFS or BFS), store `(child_node -> parent_node)` mappings in a hash map
- Modified Node Structure: Add a parent pointer to the TreeNode class.

## Tree Construction/Serialization/Deserialization
Problems that require building a tree from an array or string representation, or converting a tree into a string. Often involves using recursion and understanding how different traversals can reconstruct the tree.

When to use
- When you need to build a tree from an array/string representation, or convert a tree into a storable format.

Key Properties
- Pre-order + Null Markers: **Most common** for serialization. Use a special marker (e.g., #, null) for empty children to preserve the tree structure when deserializing
- Pre-order + In-order: If you're given both traversals, you can uniquely reconstruct a binary tree. The root is always the first in pre-order. Find it in in-order to split the array into left and right subtrees
- Level-order (BFS): Also used for serialization/deserialization, particularly when dealing with complete binary trees or when array-based representations are convenient

## Path Problems

When to use
- Problems that involve finding properties of paths in a tree

Key Properties
- Recursive DFS: Almost always solved with DFS
- State Tracking: Pass current sum/path down (top-down) or return max sum/length up
- Global Variables/Arrays: Sometimes, a global variable (or an array passed by reference) is used to store the overall maximum/minimum found across all paths, as the recursive function might only return a partial result