"""
Linked List data structure tests
"""

# Author: 
# Lajos Neto <lajosnetogit@gmail.com>


import pytest
from linked_list import LinkedList


def test_insert():
    ll = LinkedList()
    ll.insert(0, 30)
    assert [i for i in ll] == [30]
    ll.insert(0, 20)
    assert [i for i in ll] == [20, 30]
    ll.insert(0, 10)
    assert [i for i in ll] == [10, 20, 30]
    with pytest.raises(IndexError):
        ll.insert(3, 40)
    ll.insert(2, 40)
    assert [i for i in ll] == [10, 20, 40, 30]
    ll.insert(1, 10)
    assert [i for i in ll] == [10, 10, 20, 40, 30]
    ll.insert(3, 90)
    assert [i for i in ll] == [10, 10, 20, 90, 40, 30]