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

def test_empty():
    ll = LinkedList()
    assert ll.empty() == True
    ll.insert(0, 10)
    assert ll.empty() == False

def test_push_front():
    ll = LinkedList()
    ll.push_front(10)
    assert [i for i in ll] == [10]
    ll.push_front(20)
    assert [i for i in ll] == [20, 10]
    ll.push_front(30)
    assert [i for i in ll] == [30, 20, 10]

def test_front():
    ll = LinkedList()
    ll.push_front(10)
    assert ll.front() == 10
    ll.push_front(20)
    assert ll.front() == 20
    ll.push_front(30)
    assert ll.front() == 30
