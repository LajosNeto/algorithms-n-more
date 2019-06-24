"""
Queue data structure implementation
"""

# Author: 
# Lajos Neto <lajosnetogit@gmail.com>


import sys


class _Node:
    """
    Simple node used for representing values inside the queue based on linked list
    """
    def __init__(self, value):
        self.value = value
        self.next = None

class LinkedListQueue:
    """
    Queue implementation using linked list
    """
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0
    
    def __iter__(self):
        iterator = self.head
        while True:
            if iterator is None:
                return
            yield iterator.value
            iterator = iterator.next
            
    def is_empty(self):
        return self.size == 0
    
    def enqueue(self, value):
        new_node = _Node(value)
        if self.is_empty():
            self.head = new_node
            self.tail = new_node
            self.size += 1
        else:
            self.tail.next = new_node
            self.tail = new_node