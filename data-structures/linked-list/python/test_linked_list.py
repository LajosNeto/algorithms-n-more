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

def test_back():
    ll = LinkedList()
    ll.insert(0, 30)
    assert ll.back() == 30
    ll.insert(0, 20)
    assert ll.back() == 30
    ll.insert(0, 10)
    assert ll.back() == 30
    ll.insert(2, 40)
    assert ll.back() == 30
    ll.insert(1, 10)
    assert ll.back() == 30
    ll.insert(3, 90)
    assert ll.back() == 30

def test_push_back():
    ll = LinkedList()
    ll.push_back(10)
    assert ll.back() == 10
    ll.push_back(20)
    assert ll.back() == 20
    ll.push_back(30)
    assert ll.back() == 30

def test_len():
    ll = LinkedList()
    assert len(ll) == 0
    value = 10
    value_check = 1
    for i in range(10):
        ll.push_front(value)
        assert len(ll) == value_check
        value_check += 1