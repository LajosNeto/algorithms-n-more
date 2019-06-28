"""
Queue data structure tests
"""

# Author: 
# Lajos Neto <lajosnetogit@gmail.com>


import sys
import unittest
from queue import LinkedListQueue
from queue import ArrayQueue


class QueueTest(unittest.TestCase):
    def __init__(self, *args, **kwargs):
        super(QueueTest, self).__init__(*args, **kwargs)
        self.ll_queue = LinkedListQueue()
        self.arr_queue = ArrayQueue()
    
    def test_ll_queue_enqueue(self):
        self.ll_queue.enqueue(10)
        self.ll_queue.enqueue(20)
        self.ll_queue.enqueue(30)
        self.ll_queue.enqueue(40)
        self.assertEqual([i for i in self.ll_queue], [10,20,30,40])
        self.ll_queue.enqueue(50)
        self.assertEqual([i for i in self.ll_queue], [10,20,30,40,50])
    
    def test_ll_queue_dequeue(self):
        self.ll_queue.enqueue(10)
        self.ll_queue.enqueue(20)
        self.ll_queue.enqueue(30)
        self.ll_queue.enqueue(40)
        self.assertEqual(self.ll_queue.dequeue(), 10)
        self.assertEqual([i for i in self.ll_queue], [20,30,40])
        self.assertEqual(self.ll_queue.dequeue(), 20)
        self.assertEqual(self.ll_queue.dequeue(), 30)
        self.assertEqual(self.ll_queue.dequeue(), 40)
        self.assertRaises(IndexError, self.ll_queue.dequeue)
        self.ll_queue.enqueue(10)
        self.ll_queue.enqueue(20)
        self.assertEqual(self.ll_queue.dequeue(), 10)
    
    def test_arr_queue_enqueue(self):
        self.arr_queue.enqueue(10)
        self.arr_queue.enqueue(20)
        self.arr_queue.enqueue(30)
        self.arr_queue.enqueue(40)
        self.assertEqual([i for i in self.arr_queue], [10,20,30,40])
        self.arr_queue.enqueue(50)
        self.assertEqual([i for i in self.arr_queue], [10,20,30,40,50])
        self.arr_queue.enqueue(60)
        self.arr_queue.enqueue(70)
        self.assertEqual([i for i in self.arr_queue], [10,20,30,40,50,60,70])
        self.arr_queue.enqueue(80)
        self.arr_queue.enqueue(90)
        self.arr_queue.enqueue(100)
        self.arr_queue.enqueue(110)
        self.arr_queue.enqueue(120)
        self.arr_queue.enqueue(130)
        self.assertEqual([i for i in self.arr_queue], [10,20,30,40,50,60,70,80,90,100,110,120,130])
    
    def test_arr_queue_dequeue(self):
        self.arr_queue.enqueue(10)
        self.arr_queue.enqueue(20)
        self.arr_queue.enqueue(30)
        self.arr_queue.enqueue(40)
        self.assertEqual(self.arr_queue.dequeue(), 10)
        self.assertEqual([i for i in self.arr_queue], [20,30,40])
        self.assertEqual(self.arr_queue.dequeue(), 20)
        self.assertEqual(self.arr_queue.dequeue(), 30)
        self.assertEqual(self.arr_queue.dequeue(), 40)
        self.assertRaises(IndexError, self.arr_queue.dequeue)
        self.arr_queue.enqueue(10)
        self.arr_queue.enqueue(20)
        self.assertEqual(self.arr_queue.dequeue(), 10)