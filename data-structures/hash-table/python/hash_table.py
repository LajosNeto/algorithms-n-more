"""
Hash Table data structure implementation
"""

# Author: 
# Lajos Neto <lajosnetogit@gmail.com>


class HashTable:
    """Linked list node"""
    def __init__(self, hashing_function='default'):
        self.hashing_function = hashing_function