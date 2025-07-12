# Stack Patterns
stacks are a linear data structure that follows the Last-In, First-Out (LIFO) principle.

## Basic Stack
Directly applying push, pop, top, and empty operations

Should be used when
- need to maintain order in LIFO

Key Proporties
- Know when to add or remove from your stack

## Monotonic Stack
A monotonic stack maintains elements in strictly increasing or decreasing order.

Should be used when you need to find
- next greater/smaller element
- previous greater/smaller element

Key Proprties
- Push elements (or their indices) onto the stack
- If the current element breaks the monotonicity, you pop elements from the stack until the monotonicity is restored
- The popped elements are usually the ones for which you've found their "next greater/smaller" value