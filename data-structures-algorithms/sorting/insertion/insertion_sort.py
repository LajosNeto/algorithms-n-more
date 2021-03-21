"""
Insertion Sort algorithm implementation
"""

# Author:
# Lajos Neto <lajosneto@gmail.com>

def insertion_sort(sequence):
    seq_len = len(sequence)
    for j in range(1,seq_len):
        key = sequence[j]
        i = j - 1
        while i >= 0 and sequence[i] > key:
            sequence[i+1] = sequence[i]
            i -= 1
        sequence[i+1] = key
    
    return sequence