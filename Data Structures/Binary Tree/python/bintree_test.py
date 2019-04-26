# bintree_test.py
# 
# Binary Tree implementation tests
#
# author Lajos Onodi Neto

import sys
import unittest
from bintree import Bst

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
        self.bst.inorder()

if __name__ == '__main__':
    unittest.main()
    sys.exit(0)