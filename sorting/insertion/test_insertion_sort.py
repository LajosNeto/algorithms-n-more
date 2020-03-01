"""
Insertion sort tests
"""

# Author:
# Lajos Neto <lajosneto@gmail.com>


import pytest
from insertion_sort import insertion_sort


def test_insertion_sort():
    assert(insertion_sort([5,2,4,6,1,3]) == [1,2,3,4,5,6])
    assert(insertion_sort([5,2,4,6]) == [2,4,5,6])
    assert(insertion_sort([5,6,1,3]) == [1,3,5,6])
    assert(insertion_sort([5,2,6,1]) == [1,2,5,6])
    assert(insertion_sort([2,1]) == [1,2])
    assert(insertion_sort([1,2]) == [1,2])
    assert(insertion_sort([2,1,1,1,2,1,3]) == [1,1,1,1,2,2,3])
    assert(insertion_sort([2,1,1,1,3,2,1]) == [1,1,1,1,2,2,3])
    assert(insertion_sort([1]) == [1])