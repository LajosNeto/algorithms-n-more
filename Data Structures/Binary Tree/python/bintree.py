# bintree.py
# 
# Binary Tree implementation
#
# author Lajos Onodi Neto

class Node(object):
    def __init__(self, data):
        self.data = data
        self.leftChild = None
        self.rightChild = None

class Tree(object):
    def __init__(self):
        self.root = None

if __name__ == '__main__':
    print("Test")