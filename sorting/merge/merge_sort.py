"""
Merge Sort sorting algorithm implementation.
Merging subroutine is implemented based on out-of-place approach.

Time Complexity
Best case : O(nlogn)
Worst case : O(nlogn)
Average case : O(nlogn)

Space Complexity : O(n)
"""

# Author:
# Lajos Neto <lajosneto@gmail.com>


def _merge(sequence, left_index, pivot, right_index):
    left = sequence[left_index:pivot+1]
    len_left = len(left)
    right = sequence[pivot+1:right_index+1]
    len_right = len(right)
    l = 0
    r = 0
    for i in range(left_index, right_index+1):
        if (l < len_left) and (r < len_right):
            if left[l] <= right[r]:
                sequence[i] = left[l]
                l += 1
            else:
                sequence[i] = right[r]
                r += 1
        else:
            if l < len_left:
                sequence[i] = left[l]
                l += 1
            else:
                sequence[i] = right[r]
                r += 1



def _merge_sort(sequence, left_index, right_index):
    if(left_index<right_index):
        pivot = (left_index+right_index)//2
        _merge_sort(sequence, left_index, pivot)
        _merge_sort(sequence, pivot+1, right_index)
        _merge(sequence, left_index, pivot, right_index)


def merge_sort(sequence):
    _merge_sort(sequence, 0, (len(sequence)-1))