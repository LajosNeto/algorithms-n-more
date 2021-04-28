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

    @Test
    fun postBfsPathTest() {
        val bst = Bst()
        bst.put(49)
        bst.put(46)
        bst.put(79)
        bst.put(43)
        bst.put(64)
        bst.put(83)
        assert(bst.getBfsOrder() == mutableListOf(49, 46, 79, 43, 64, 83))
        bst.put(41)
        bst.put(77)
        bst.put(95)
        assert(bst.getBfsOrder() == mutableListOf(49, 46, 79, 43, 64, 83, 41, 77, 95))
    }

    @Test
    fun minTest() {
        val bst = Bst()
        bst.put(50)
        assert(bst.min() == 50)
        bst.put(40)
        assert(bst.min() == 40)
        bst.put(70)
        bst.put(45)
        bst.put(20)
        assert(bst.min() == 20)
        bst.put(23)
        bst.put(10)
        assert(bst.min() == 10)
    }

    @Test
    fun maxTest() {
        val bst = Bst()
        bst.put(50)
        assert(bst.max() == 50)
        bst.put(40)
        bst.put(70)
        assert(bst.max() == 70)
        bst.put(45)
        bst.put(90)
        assert(bst.max() == 90)
        bst.put(85)
        assert(bst.max() == 90)
        bst.put(100)
        assert(bst.max() == 100)
    }

    @Test
    fun hasTest() {
        val bst = Bst()
        bst.put(49)
        assert(bst.has(49))
        bst.put(46)
        assert(bst.has(46))
        bst.put(79)
        bst.put(43)
        bst.put(64)
        bst.put(83)
        bst.put(41)
        bst.put(77)
        bst.put(95)
        assert(bst.has(79))
        assert(bst.has(43))
        assert(bst.has(64))
        assert(bst.has(83))
        assert(bst.has(41))
        assert(bst.has(77))
        assert(bst.has(95))
    }

    @Test
    fun parentTest() {
        val bst = Bst()
        bst.put(49)
        assert(bst.parent(46) == null)
        bst.put(46)
        assert(bst.parent(46)?.value == 49)
        bst.put(79)
        assert(bst.parent(79)?.value == 49)
        bst.put(43)
        assert(bst.parent(43)?.value == 46)
        bst.put(64)
        assert(bst.parent(64)?.value == 79)
        bst.put(83)
        assert(bst.parent(83)?.value == 79)
        bst.put(41)
        assert(bst.parent(41)?.value == 43)
        bst.put(77)
        assert(bst.parent(77)?.value == 64)
        bst.put(95)
        assert(bst.parent(95)?.value == 83)
    }
}