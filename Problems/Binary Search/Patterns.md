# Binary Search
Highly efficient for searching in sorted data.

## Basic Binary Search
Given a sorted array and a target value, find if the target exists and return its index.

When to Use:
- You have a sorted array (or list).
- You need to find if a specific target value exists in the array.
- You need to return the index of the target if found.

## Finding First/Last Occurrence of a Target
When there are duplicate elements in a sorted array, you might need to find the first or last index of a target.

When to Use:
- You have a sorted array (or list) that might contain duplicate elements.
- You need to find the first index where a target appears.
- You need to find the last index where a target appears.

Key Proporties
- Modification of Basic Binary Search
    - The setup is similar, but the action taken when `nums[mid] == target` changes.
- For First Occurrence
    - if `mid == target`, could be the first occurrence, store it as a potential answer
    - then search the left half and update as needed
    - if `mid < target`, search right; if `mid > target`, search left.
- For Last Occurrence
    - if `mid == target`, could be the last occurrence, store it as a potential answer
    - then search the right half and update as needed
    - if `mid < target`, search right; if `mid > target`, search left.

## Finding Smallest/Largest Element
The problem isn't explicitly about searching a sorted array, but you can define a monotonic "condition function" that can be checked using binary search. The search space is often a range of possible answers, not indices in an array.

When to use
- asks for min X value for a condition
- asks for max X value for a condition
- Condition must be monotonic
- usually a range of possible answers

Key Proporties
- set the search space for all possible values of your answer
- for min
    - find mid
    - test if mid works/is true
    - if mid is true, try to find a smaller one and save that value
    - if mid is false, try to find a larger value
    - return that saved value
- for max
    - find mid
    - test if mid works/is true
    - if mid is true, try to find a larger value and save that value
    - if mid is false, try to find a smaller value
    - return that saved value