# bst.py
# 
# Binary Tree (BST) implementation
#
# author Lajos Onodi Neto


import queue


class Node(object):
    """
    BST node that holds reference to left child, right child
    and also to the value stored within itself.
    """
    def __init__(self, value):
        self._value = value
        self._left_child = None
        self._right_child = None


class Bst(object):
    def __init__(self):
        self._root = None
        self._size = 0
    
    def insert(self, value):
        """
        Recursively insert a new value inside the BST.
        Returns true if successful and false if value already exists.
        """
        if(self._root):
            return self.__insert(self._root, value)
        else:
            self._root = Node(value)
            self._size += 1
            return True
        
    def __insert(self, root, value):
        if(root._value == value):
            return False
        elif value < root._value:
            if(root._left_child):
                return self.__insert(root._left_child, value)
            else:
                root._left_child = Node(value)
                self._size += 1
                return True
        else:
            if(root._right_child):
                return self.__insert(root._right_child, value)
            else:
                root._right_child = Node(value)
                self._size += 1
                return True

    def dfs_inorder(self):
        """
        Prints BST content following inorder walking
        """
        self.__inorder(self._root)

    def __inorder(self, root):
        if(root):
            self.__inorder(root._left_child)
            print(root._value)
            self.__inorder(root._right_child)
    
    def dfs_preorder(self):
        """
        Prints BST content following preorder walking
        """
        self.__preorder(self._root)

    def __preorder(self, root):
        if(root):
            print(root._value)
            self.__inorder(root._left_child)
            self.__inorder(root._right_child)

    def dfs_postorder(self):
        """
        Prints BST content following preorder walking
        """
        self.__postorder(self._root)

    def __postorder(self, root):
        if(root):
            self.__inorder(root._left_child)
            self.__inorder(root._right_child)
            print(root._value)
    
    def bfs(self):
         """
         Visits BST nodes following the Breadth-first 
         tree traversal approach
         """
         node_queue = [self._root]
         node_bfs_order = []
         self.__bsf(node_queue, node_bfs_order)
         return node_bfs_order

    def __bsf(self, node_queue, node_bfs_order):
        if node_queue:
            cur_node = node_queue.pop()
            if cur_node._left_child:
                node_queue.insert(0, cur_node._left_child)
            if cur_node._right_child:
                node_queue.insert(0, cur_node._right_child)
            node_bfs_order.append(cur_node._value)
            self.__bsf(node_queue, node_bfs_order)
    
    def search_value(self, value):
        """
        Search for a given value inside the BST.
        """
        return self.__search_value(self._root, value)

    def __search_value(self, root, value):
        if(root._value == value):
            return True
        if(value < root._value):
            if(root._left_child):
                return self.__search_value(root._left_child, value)
            else:
                 return False
        else:
            if(root._right_child):
                return self.__search_value(root._right_child, value)
            else:
                return False

if __name__ == '__main__' :
    bst = Bst()
    bst.insert(10)
    bst.insert(5)
    bst.insert(15)
    bst.insert(6)
    bst.insert(2)
    bst.insert(1)
    bst.insert(3)
    bst.insert(20)
    bst.insert(12)
    bst.insert(14)
    bst.insert(13)
    bst.insert(21)
    bst.insert(22)
    bst.insert(23)
    bst.insert(24)
    bst.insert(25)
    bst.bfs()