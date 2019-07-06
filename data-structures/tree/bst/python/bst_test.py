# bst_test.py
# 
# Binary Tree (BST) implementation tests
#
# author Lajos Onodi Neto

import sys
import unittest
from bst import Bst

class BstTest(unittest.TestCase):
    def __init__(self, *args, **kwargs):
        super(BstTest, self).__init__(*args, **kwargs)
        self.bst = Bst()
        self.bst.insert(10)
        self.bst.insert(5)
        self.bst.insert(15)
    
    def test_insert(self):
        self.assertTrue(self.bst.insert(20))
        self.assertTrue(self.bst.insert(2))
        self.assertTrue(self.bst.insert(12))
        self.assertFalse(self.bst.insert(5))
    
    def test_size_counter(self):
        self.assertEqual(self.bst._size, 3)
        self.assertTrue(self.bst.insert(20))
        self.assertTrue(self.bst.insert(1))
        self.assertEqual(self.bst._size, 5)
    
    def test_display(self):
        print("Inorder traversal :")
        self.bst.dfs_inorder()
        print("Preorder traversal :")
        self.bst.dfs_preorder()
        print("Postorder traversal :")
        self.bst.dfs_postorder()
    
    def test_bfs(self):
        self.bst.insert(6)
        self.bst.insert(2)
        self.bst.insert(1)
        self.bst.insert(3)
        self.bst.insert(20)
        self.bst.insert(12)
        self.bst.insert(14)
        self.bst.insert(13)
        self.bst.insert(21)
        self.bst.insert(22)
        self.bst.insert(23)
        bfs_order = self.bst.bfs()
        self.assertEqual(bfs_order, [10,5,15,2,6,12,20,1,3,14,21,13,22,23])
    
    def test_node_count(self):
        self.bst.insert(6)
        self.assertEqual(self.bst.node_count(), 4)
        self.bst.insert(2)
        self.assertEqual(self.bst.node_count(), 5)
        self.bst.insert(1)
        self.bst.insert(3)
        self.bst.insert(20)
        self.bst.insert(12)
        self.bst.insert(14)
        self.assertEqual(self.bst.node_count(), 10)
        self.bst.insert(13)
        self.bst.insert(21)
        self.assertEqual(self.bst.node_count(), 12)
        self.bst.insert(22)
        self.bst.insert(23)
        self.assertEqual(self.bst.node_count(), 14)
    
    def test_min(self):
        self.assertEqual(self.bst.min(), 5)
        self.bst.insert(20)
        self.bst.insert(12)
        self.bst.insert(14)
        self.assertEqual(self.bst.min(), 5)
        self.bst.insert(13)
        self.bst.insert(21)
        self.assertEqual(self.bst.min(), 5)
        self.bst.insert(22)
        self.bst.insert(23)
        self.bst.insert(6)
        self.assertEqual(self.bst.min(), 5)
        self.bst.insert(2)
        self.assertEqual(self.bst.min(), 2)
        self.bst.insert(1)
        self.assertEqual(self.bst.min(), 1)
        self.bst.insert(3)
        self.assertEqual(self.bst.min(), 1)

if __name__ == '__main__':
    unittest.main()
    sys.exit(0)