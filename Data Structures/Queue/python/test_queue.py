"""
Queue data structure tests
"""

# Author: 
# Lajos Neto <lajosnetogit@gmail.com>


import sys
import unittest
from queue import LinkedListQueue


class QueueTest(unittest.TestCase):
    def __init__(self, *args, **kwargs):
        super(QueueTest, self).__init__(*args, **kwargs)
        self.ll_queue = LinkedListQueue()
    
    def test_ll_queue_enqueue(self):
        self.ll_queue.enqueue(10)
        self.ll_queue.enqueue(20)
        self.ll_queue.enqueue(30)
        self.ll_queue.enqueue(40)
        self.assertEqual([i for i in self.ll_queue], [10,20,30,40])
        self.ll_queue.enqueue(50)
        self.assertEqual([i for i in self.ll_queue], [10,20,30,40,50])