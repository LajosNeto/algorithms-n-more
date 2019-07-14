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
    
    def __iter__(self):
        iterator = self._top
        while True:
            if iterator is None:
                return
            yield iterator.value
            iterator = iterator.next
    
    def empty(self):
        """Check if the list is empty"""
        return self._size == 0
    
    def push(self, value):
        """Push new value on top of the stack"""
        new_node = _Node(value)
        if self.empty():
            self._top = new_node
            self._bottom = new_node
        else:
            new_node.next = self._top
            self._top = new_node
        self._size += 1
    
    def pop(self):
        """Pop value on top of the stack"""
        if self.empty():
            raise IndexError("Empty stack")
        pop_value = self._top.value
        self._top = self._top.next
        self._size -= 1
        return pop_value