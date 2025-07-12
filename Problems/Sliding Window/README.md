# Sliding Window Patterns
Core idea:
Instead of reprocessing the same elements repeatedly (e.g., in nested loops), we use two pointers (often called start and end or left and right) to create a "window" that moves over the input—typically a string or array. The key is to efficiently manage only the elements entering and leaving the window. In practice make sure to only handle information coming in and out.

## Fixed Window
Should be used when 
- The window size k is constant
- You're asked to calculate values for every subarray or substring of size k

Key Properties
- Window size = fixed (right - left + 1 == k)
- Only move right and left in sync to keep size constant

## Dynamic Window
Should be used when 
- You don't know the window size ahead of time 
- To find a minimum or maximum length of a subarray or substring that satisfies a condition 
- The condition depends on window contents, not just size

Key Properties
- You expand right to grow the window until a condition is met
- Then, you contract left to shrink the window and try to tighten the result
- Usually involves checking validity inside a while loop

## Dynamic w/ Data Structure Window
Should be used when:
- You need to track frequencies, counts, or state of elements inside the window
- You care about distinct characters, duplicates, or match counts (e.g., anagram, substring contains)
- The check for window validity is not trivial and needs some tracking data

Common Data Structures
- Hash Map (for character counts or frequency)
- Hash Set (for distinct elements)
- deque (in monotonic window problems)