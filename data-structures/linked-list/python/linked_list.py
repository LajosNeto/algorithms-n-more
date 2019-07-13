"""
Linked List data structure implementation
"""

# Author: 
# Lajos Neto <lajosnetogit@gmail.com>


class _Node:
    """
    Simple node used for representing values 
    inside the linked list.
    """
    def __init__(self, value):
        self.value = value
        self.next = None

class LinkedList:
    """
    Linked List main class where all value nodes
    are stored within.
    """
    def __init__(self):
        self._head = None
        self._tail = None
        self._size = 0
    
    def __iter__(self):
        iterator = self._head
        while True:
            if iterator is None:
                return
            yield iterator.value
            iterator = iterator.next
    
    def empty(self):
        """Check if the list is empty"""
        return self._size == 0
    
    def insert(self, index, value):
        """Insert a vulue at a given index position"""
        new_node = _Node(value)
        if self.empty() or index == 0:
            self.push_front(value)
        elif index >= self._size or index < 0:
            raise IndexError
        else:
            aux_pointer = self._head
            for i in range(index-1):
                aux_pointer = aux_pointer.next
            new_node.next = aux_pointer.next
            aux_pointer.next = new_node
            self._size += 1
    
    def front(self):
        """Returns the first value on the list"""
        return self._head.value
    
    def push_front(self, value):
        """Insert a value at the beginning of the list"""
        new_node = _Node(value)
        if self.empty():
            self._head = new_node
            self._tail = new_node
        else:
            new_node.next = self._head
            self._head = new_node
        self._size += 1
