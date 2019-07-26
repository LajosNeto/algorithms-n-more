"""
Hash Table data structure implementation
"""

# Author: 
# Lajos Neto <lajosnetogit@gmail.com>


class HashTable:
    """
    Hash table data structure implementation.
    This implementation uses chaining for collision resolution.
    This data structure basically receives a pair (key, value) 
    and add it to the hash tabel structure.
    """
    MIN_SIZE = 8

    def __init__(self, hashing_function='division'):
        self._size = self.MIN_SIZE
        self._slots = [[] for _ in range(self._size)]
        self._hashing_function = hashing_function
        self._len = 0
    
    def _hash(self, key):
        """
        Applies hashing process to a given key and return an index 
        from the table slots. This is done in two steps :
        1. Checks if the key is a string and returns the equivalent 
        sum of its ASCII values.
        2. Applies the key hashing to an index in the slots range
        """
        key = sum(ord(c) for c in key) if type(key) is str else key
        return {
             'division': lambda: key % self._size
        }.get(self._hashing_function, lambda: None)()
    
    def put(self, key, value):
        """
        Inserts a key and value pair inside the hash table.
        The collisions are ignored as a chaining approach is taken.
        """
        index = self._hash(key)
        self._slots[index].append((key,value))
        self._len += 1