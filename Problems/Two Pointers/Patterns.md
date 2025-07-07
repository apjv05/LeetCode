# Two Pointers
Core idea is to use two different points that point to different data in a data structure which you can then move and manipulate. The is key is to know when to move them and what to do.

## Oposing Ends
Start two pointers at opposite ends of the array or string and move them toward each other based on logic.

Should be used when
- Pairs with a target sum.
- Removing elements based on conditions.
- Checking for palindromes.
- Maximizing/minimizing something between both ends (like area or distance).

key properties
- left++ when its too small.
- right-- when its too big.

Works best when data is sorted (or can be sorted).

## Fast and slow
Have one pointer move faster than the other, usually at twice the speed. Used when you need to detect cycles, middle points, or manage traversal without extra memory.

Should be used when
- You're dealing with cyclic structures like linked lists.
- You need to find a middle, detect cycles, or partition a structure.