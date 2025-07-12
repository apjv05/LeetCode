# Hashing and Prefix Sums Patterns

## Hash table
Used to find and store data in constant time.

### Find Duplicates
Use a hash set to check for duplicates. Hash set provides O(1) average-time lookups and insertions. Brute-force is O(n²).

### Frequency
Count how often elements appear using a hash map. Counting in a map makes frequency-based logic simple and efficient.

## Prefix Sums
Precompute sums of subarrays from index 0 to i, and use it to get range sums in O(1).

Common Use Cases:
- Subarray sums
- Count subarrays with target sum
- Optimizing range queries