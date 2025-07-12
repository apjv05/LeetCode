# Binary Search Patterns
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

### Rotated Sorted Array
An array that was originally sorted but then rotated at some pivot point (e.g., `[4,5,6,7,0,1,2]`). The challenge is that the mid element doesn't necessarily tell you if the left or right half is sorted.

When to use
- You need to find a target value within a rotated array

Key Proporties
- Identify the Sorted Half
    - atleast one have of the array must be sorted in an ascending order
- Determine the location
    - For left
        - Check if the target falls within this sorted left half `nums[left] <= target < nums[mid]`.
        - If yes, search left
        - If no, search right 
    - For right
        - This means the pivot is in the left half, and mid is in the right sorted portion.
        - Check if the target falls within this sorted right half `nums[mid] < target <= nums[right]`.
        - If yes, search right
        - If no, search left
- Edge Cases
    - If duplicates are present it becomes harder to determine the sorted half when `nums[left] == nums[mid] == nums[right]`. 
    - increment left (or decrement right) to shrink the search space, as nums[left] doesn't give useful information.