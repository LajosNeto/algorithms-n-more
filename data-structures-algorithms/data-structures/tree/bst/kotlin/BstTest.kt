/**
 * BST (Binary Search Tree) implementation tests.
 *
 * Author : Lajos Neto.
 * Email : lajosnetogit@gmail.com
 */

import org.junit.Test

class BstTest {

    @Test
    fun inOrderPathTest() {
        val bst = Bst()
        bst.put(49)
        bst.put(46)
        bst.put(79)
        bst.put(43)
        bst.put(64)
        bst.put(83)
        assert(bst.getInOrder() == mutableListOf(43, 46, 49, 64, 79, 83))
    }

    @Test
    fun preOrderPathTest() {
        val bst = Bst()
        bst.put(49)
        bst.put(46)
        bst.put(79)
        bst.put(43)
        bst.put(64)
        bst.put(83)
        assert(bst.getPreOrder() == mutableListOf(49, 46, 43, 79, 64, 83))
    }

    @Test
    fun postOrderPathTest() {
        val bst = Bst()
        bst.put(49)
        bst.put(46)
        bst.put(79)
        bst.put(43)
        bst.put(64)
        bst.put(83)
        assert(bst.getPostOrder() == mutableListOf(43, 46, 64, 83, 79, 49))
    }
}