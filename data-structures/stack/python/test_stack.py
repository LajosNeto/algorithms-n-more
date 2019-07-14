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
