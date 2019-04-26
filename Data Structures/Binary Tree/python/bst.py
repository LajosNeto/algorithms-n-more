# bst.py
# 
# Binary Tree (BST) implementation
#
# author Lajos Onodi Neto

class Node(object):
    """
    BST node that holds reference to left child, right child
    and also to the value stored within itself.
    """
    def __init__(self, value):
        self.value = value
        self.leftChild = None
        self.rightChild = None


class Bst(object):
    def __init__(self):
        self.root = None
    
    def insert(self, value):
        """
        Recursively insert a new value inside the BST.
        Returns true if successful and false if value already exists.
        """
        if(self.root):
            return self.__insert(self.root, value)
        else:
            self.root = Node(value)
            return True
        
    def __insert(self, root, value):
        if(root.value == value):
            return False
        elif value < root.value:
            if(root.leftChild):
                return self.__insert(root.leftChild, value)
            else:
                root.leftChild = Node(value)
                return True
        else:
            if(root.rightChild):
                return self.__insert(root.rightChild, value)
            else:
                root.rightChild = Node(value)
                return True

    def inorder(self):
        """
        Prints BST content following inorder walking
        """
        self.__inorder(self.root)

    def __inorder(self, root):
        if(root):
            self.__inorder(root.leftChild)
            print(root.value)
            self.__inorder(root.rightChild)
    
    def preorder(self):
        """
        Prints BST content following preorder walking
        """
        self.__preorder(self.root)

    def __preorder(self, root):
        if(root):
            print(root.value)
            self.__inorder(root.leftChild)
            self.__inorder(root.rightChild)

# if __name__ == '__main__' :
#     bst = Bst()
#     bst.insert(10)
#     bst.insert(5)
#     bst.insert(15)
#     bst.insert(20)
#     bst.insert(2)
#     bst.insert(12)
#     bst.inorder()