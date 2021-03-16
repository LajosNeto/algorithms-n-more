/**
 * Linked List tests.
 * 
 * Author : Lajos Neto.
 * Email : lajosnetogit@gmail.com
 */

import org.junit.Test

class LinkedListTest {

    @Test
    fun addBeginTest() {
        val ll = LinkedList<Int>()
        ll.addBegin(30)
        ll.addBegin(20)
        ll.addBegin(10)
        ll.addBegin(0)
        assert(ll.toString() == "0 -> 10 -> 20 -> 30 -> /null")
    }

    @Test
    fun addEndTest() {
        val ll = LinkedList<Int>()
        ll.addBegin(30)
        ll.addBegin(20)
        ll.addBegin(10)
        ll.addEnd(40)
        ll.addEnd(50)
        ll.addBegin(0)
        assert(ll.toString() == "0 -> 10 -> 20 -> 30 -> 40 -> 50 -> /null")
    }

    @Test
    fun removeBeginTest() {
        val ll = LinkedList<Int>()
        ll.addBegin(30)
        ll.addBegin(20)
        ll.addBegin(10)
        ll.addBegin(0)
        ll.addEnd(40)
        ll.removeBegin()
        assert(ll.toString() == "10 -> 20 -> 30 -> 40 -> /null")
        ll.removeBegin()
        ll.removeBegin()
        assert(ll.toString() == "30 -> 40 -> /null")
    }

    @Test
    fun removeEndTest() {
        val ll = LinkedList<Int>()
        ll.addBegin(30)
        ll.addBegin(20)
        ll.addBegin(10)
        ll.addBegin(0)
        ll.addEnd(40)
        ll.removeEnd()
        assert(ll.toString() == "0 -> 10 -> 20 -> 30 -> /null")
        ll.removeEnd()
        ll.removeEnd()
        assert(ll.toString() == "0 -> 10 -> /null")
        ll.addEnd(20)
        ll.addEnd(30)
        ll.removeEnd()
        assert(ll.toString() == "0 -> 10 -> 20 -> /null")
    }

    @Test
    fun getFrontTest() {
        val ll = LinkedList<Int>()
        ll.addBegin(30)
        assert(ll.front() == 30)
        ll.addBegin(20)
        assert(ll.front() == 20)
        ll.addBegin(10)
        assert(ll.front() == 10)
        ll.addBegin(0)
        assert(ll.front() == 0)
    }

    @Test
    fun getBackTest() {
        val ll = LinkedList<Int>()
        ll.addEnd(40)
        assert(ll.back() == 40)
        ll.addEnd(50)
        assert(ll.back() == 50)
        ll.addEnd(60)
        assert(ll.back() == 60)
        ll.addEnd(70)
        assert(ll.back() == 70)
    }
}