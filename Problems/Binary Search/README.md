# Binary Search Patterns
Highly efficient for searching in sorted data.

## Basic Binary Search
Given a sorted array and a target value, find if the target exists and return its index.

When to Use:
- You have a sorted array (or list)
- You need to find if a specific target value exists in the array
- You need to return the index of the target if found

## Finding First/Last Occurrence of a Target
When there are duplicate elements in a sorted array, you might need to find the first or last index of a target.

When to Use:
- You have a sorted array (or list) that might contain duplicate elements
- You need to find the first index where a target appears
- You need to find the last index where a target appears

Key Properties
- Modification of Basic Binary Search
    - The setup is similar, but the action taken when `nums[mid] == target` changes
- For First Occurrence
    - if `mid == target`, could be the first occurrence, store it as a potential answer
    - then search the left half and update as needed
    - if `mid < target`, search right; if `mid > target`, search left
- For Last Occurrence
    - if `mid == target`, could be the last occurrence, store it as a potential answer
    - then search the right half and update as needed
    - if `mid < target`, search right; if `mid > target`, search left

## Finding Smallest/Largest Element
The problem isn't explicitly about searching a sorted array, but you can define a monotonic "condition function" that can be checked using binary search. The search space is often a range of possible answers, not indices in an array.

When to use
- asks for min X value for a condition
- asks for max X value for a condition
- Condition must be monotonic
- usually a range of possible answers

Key Properties
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

## Rotated Sorted Array
An array that was originally sorted but then rotated at some pivot point (e.g., `[4,5,6,7,0,1,2]`). The challenge is that the mid element doesn't necessarily tell you if the left or right half is sorted.

When to use
- You need to find a target value within a rotated array

Key Properties

There are  two ways to solve this problem. The first is:
- Find our range
- Identify the pivot
    - where its the smallest value
    - can be done with `while(low < high)` to find the pivot (smallest value)
        - find the mid
        - if the value of the mid is > the value of the high, than we know the smaller half is in the right half and we can set low = mid + 1
        - if not, then we know that the smaller value is in the left half so we can set high = mid
        - the pivot will be low
- Do logic as needed

the second is:
- Find our range
- find mid
- Now we have to figure out if we're in the right half or the left half
    - left half
        - the the value of our low is < the value of our mid, then we have found the left half
        - now update high and low with our target in mind and set low or high = mid +- 1/do logic
    - right half
        - if the value of low > the value of our mid, we've found the right half
        - now update high and low with our target in mind and set low or high = mid +- 1/do logic

Edge Cases
- If duplicates exist in our array then it becomes difficult to figure out which half we're in when low == mid == high
- to address this, increment left (or decrement right) to shrink the search space when we cant figure out which half we're in