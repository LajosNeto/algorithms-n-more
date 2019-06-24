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
    
    def test_display(self):
        print("Inorder traversal :")
        self.bst.dfs_inorder()
        print("Preorder traversal :")
        self.bst.dfs_preorder()
        print("Postorder traversal :")
        self.bst.dfs_postorder()

if __name__ == '__main__':
    unittest.main()
    sys.exit(0)