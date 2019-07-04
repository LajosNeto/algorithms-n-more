"""
Queue data structure implementation
"""

# Author: 
# Lajos Neto <lajosnetogit@gmail.com>


import sys
from abc import ABC, abstractmethod


class BaseQueue(ABC):
    """
    Base abstract class for queue implementation.
    """
    def __init__(self):
        super().__init__()
        self._size = 0
    
    def __len__(self):
        return self._size
    
    def is_empty(self):
        return self._size == 0
    
    @abstractmethod
    def enqueue(self, value):
        pass
    
    @abstractmethod
    def dequeue(self):
        pass
    
    @abstractmethod
    def __iter__(self):
        pass

class _Node:
    """
    Simple node used for representing values 
    inside the queue based on linked list.
    """
    def __init__(self, value):
        self.value = value
        self.next = None

class LinkedListQueue(BaseQueue):
    """
    Queue implementation using linked list.
    """
    def __init__(self):
        super().__init__()
        self._head = None
        self._tail = None
    
    def __iter__(self):
        iterator = self._head
        while True:
            if iterator is None:
                return
            yield iterator.value
            iterator = iterator.next
            
    def is_empty(self):
        return self._size == 0
    
    def enqueue(self, value):
        new_node = _Node(value)
        if self.is_empty():
            self._head = new_node
            self._tail = new_node
        else:
            self._tail.next = new_node
            self._tail = new_node
        self._size += 1
    
    def dequeue(self):
        if self.is_empty():
            raise IndexError("Empty queue")
        dequeued_value = self._head.value
        if self._tail is self._head:
            self._tail = None
            self._head = None
        else:
            self._head = self._head.next
        self._size -= 1
        return dequeued_value
    
class ArrayQueue(BaseQueue):
    """
    Queue implementation using arrays.
    Even though arrays in Python being dynamic, 
    here we simulate as if they were static.
    """
    def __init__(self):
        super().__init__()
        self._array = [None] * 5
        self._head = 0
        self._tail = 0
    
    def __iter__(self):
        iterator = self._head
        while True:
            if iterator == self._tail:
                return
            yield self._array[iterator]
            iterator += 1
    
    def is_empty(self):
        return self._size == 0
    
    def enqueue(self, value):
        if self._tail == len(self._array):
            self._expand()
        self._array[self._tail] = value
        self._tail += 1
        self._size += 1
    
    def dequeue(self):
        if(self.is_empty()):
            raise IndexError("Empty queue")
        dequeued_value = self._array[self._head]
        self._array[self._head] = None
        self._head += 1
        self._size -= 1
        self._shrink()
        return dequeued_value
    
    def _expand(self):
        self._array += [None] * 5
    
    def _shrink(self):
        if(self._size/len(self._array) >= 2):
            aux_array = [i for i in a if i != None]
            self._array = aux_array
            self._size = len(self._array)