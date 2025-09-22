# Q1
"""O(n) because it iterates over every element in Y"""
# Q2
"""Binary search has complexity of O(log(n)) because each iteration halves the search space."""

# Q3
"""O(n) because it iterates once per element in the range of n. It does this twice (O(2n)) but constants don't effect time complexity. """

# Q4
"""O(log(n)) because each iteration halves the number. k is unused."""

# Q5
"""O(n) where n is the total number of integers contained in the 2D array, since it only iterates over each element once. The script is identical to iterating once over mat = [1,2,3,1,1,1,5,6,7]"""

# Q6
"""The script has an exponential time complexity because each iteration doubles how many loops are executed"""

# Q7
def log2(n):
    exponent = 0
    while 2 ** exponent < n:
        exponent += 1
    return exponent
print(log2(16))
import math
print(math.log2(16))

# Q8
def has_duplicate_pairs(nums):
    seen = dict()
    for n in nums:
        if seen.get(n):
            return True
        seen[n] = True
    return False
print(has_duplicate_pairs([1,2,3,4,5]))
print(has_duplicate_pairs([1,2,3,2]))
print(has_duplicate_pairs([7, 7, 7, 7]))
