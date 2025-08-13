# Two Heaps Patterns

## K-th Element
This pattern is used to efficiently find the K-th smallest or largest element in a collection of data. It's often more efficient than sorting the entire array, especially when K is much smaller than the size of the array

When to use
- Use this pattern when you need to find the K-th smallest or largest item from a large collection without fully sorting it

Key Properties
- To find the K-th largest element, you maintain a min-heap of size K
    - iterate through the collection, adding elements to the heap
    - If the heap's size exceeds K, you remove the smallest element (the root). This ensures the heap always contains the K largest elements encountered so far
    - After processing all elements, the root of the heap is the answer
- to find the K-th smallest element
    - use a max-heap of size K
    - add elements and, if the size exceeds K, you remove the largest element
    - The remaining element at the root is the K-th smallest

## Merge K Sorted Lists/Arrays
used to merge multiple sorted lists or arrays into a single sorted list. A naive approach would be to concatenate all lists and then sort, but a heap-based approach is much more efficient, especially with many lists

When to use
- when you need to merge multiple already sorted collections into a single, sorted collection

Key Properties
- The core idea is to always have access to the smallest available element from all the lists combined. A min-heap is perfect for this
- initially populate the heap with the first element from each of the K lists
- In a loop, you extract the minimum element from the heap
- You then add the next element from the same list back into the heap. This process continues until the heap is empty