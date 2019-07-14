"""
Stack data structure tests
"""

# Author: 
# Lajos Neto <lajosnetogit@gmail.com>


import pytest
from stack import Stack

def test_empty():
    st = Stack()
    assert st.empty() == True

def test_push():
    st = Stack()
    st.push(10)
    assert [i for i in st] == [10]
    st.push(20)
    assert [i for i in st] == [20, 10]
    st.push(30)
    assert [i for i in st] == [30, 20, 10]
    st.push(40)
    assert [i for i in st] == [40, 30, 20, 10]
    st.push(50)
    assert [i for i in st] == [50, 40, 30, 20, 10]
    st.push(60)
    assert [i for i in st] == [60, 50, 40, 30, 20, 10]
    st.push(70)
    assert [i for i in st] == [70, 60, 50, 40, 30, 20, 10]
    st.push(80)
    assert [i for i in st] == [80, 70, 60, 50, 40, 30, 20, 10]