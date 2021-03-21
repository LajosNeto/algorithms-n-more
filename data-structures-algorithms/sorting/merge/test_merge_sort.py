"""
Merge sort tests
"""

# Author:
# Lajos Neto <lajosneto@gmail.com>


import pytest
from merge_sort import merge_sort


def test_merge_sort():
    assert(merge_sort([5,2,4,6,1,3]) == [1,2,3,4,5,6].sort())
    assert(merge_sort([5,2,4,6]) == [2,4,5,6].sort())
    assert(merge_sort([5,6,1,3]) == [1,3,5,6].sort())
    assert(merge_sort([5,2,6,1]) == [1,2,5,6].sort())
    assert(merge_sort([2,1]) == [1,2].sort())
    assert(merge_sort([1,2]) == [1,2].sort())
    assert(merge_sort([2,1,1,1,2,1,3]) == [1,1,1,1,2,2,3].sort())
    assert(merge_sort([2,1,1,1,3,2,1]) == [1,1,1,1,2,2,3].sort())
    assert(merge_sort([1]) == [1].sort())
    assert(merge_sort([1,0,-1]) == [1,0,-1].sort())
