#!/usr/bin/env python3

def q1_sum(arrs):
    total = 0
    for arr in arrs:
        for i in arr:
            if i % 2 == 0:
                total += i
    return total

print(q1_sum([
    [1, 0, 2],
    [5, 5, 7],
    [9, 4, 3]
]))
    
