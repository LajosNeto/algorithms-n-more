"""
Stack data structure implementation based on linked lists
"""

# Author: 
# Lajos Neto <lajosnetogit@gmail.com>


class _Node:
    """
    Simple node used for representing values 
    inside the stack.
    """
    def __init__(self, value):
        self.value = value
        self.next = None
    
class Stack:
    """
    Stack data structure.
    """
    def __init__(self):
        self._top = None
        self._bottom = None
        self._size = 0
    
    def empty(self):
        """Check if the list is empty"""
        return self._size == 0
