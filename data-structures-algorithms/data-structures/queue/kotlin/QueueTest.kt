/**
 * Queue tests.
 *
 * Author : Lajos Neto.
 * Email : lajosnetogit@gmail.com
 */

import org.junit.Test

class QueueTest {

    @Test
    fun enqueueTest() {
        val qu = Queue<Int>()
        assert(qu.toString() == "/null")
        qu.enqueue(10)
        assert(qu.toString() == "10 -> /null")
        qu.enqueue(20)
        assert(qu.toString() == "10 -> 20 -> /null")
        qu.enqueue(30)
        assert(qu.toString() == "10 -> 20 -> 30 -> /null")
        qu.enqueue(40)
        assert(qu.toString() == "10 -> 20 -> 30 -> 40 -> /null")
    }

    @Test
    fun dequeueTest() {
        val qu = Queue<Int>()
        qu.enqueue(10)
        qu.enqueue(20)
        qu.enqueue(30)
        qu.enqueue(40)
        qu.dequeue()
        assert(qu.toString() == "20 -> 30 -> 40 -> /null")
        qu.dequeue()
        assert(qu.toString() == "30 -> 40 -> /null")
        qu.dequeue()
        assert(qu.toString() == "40 -> /null")
        qu.dequeue()
        assert(qu.toString() == "/null")
    }

    @Test
    fun frontTest() {
        val qu = Queue<Int>()
        assert(qu.front() == null)
        qu.enqueue(10)
        assert(qu.front() == 10)
        qu.enqueue(20)
        assert(qu.front() == 10)
        qu.enqueue(30)
        assert(qu.front() == 10)
        qu.enqueue(40)
        assert(qu.front() == 10)
    }

    @Test
    fun sizeTest() {
        val qu = Queue<Int>()
        assert(qu.size() == 0)
        qu.enqueue(10)
        assert(qu.size() == 1)
        qu.enqueue(20)
        assert(qu.size() == 2)
        qu.enqueue(30)
        assert(qu.size() == 3)
        qu.enqueue(40)
        assert(qu.size() == 4)
    }

    @Test
    fun isEmptyTest() {
        val qu = Queue<Int>()
        assert(qu.isEmpty())
        qu.enqueue(10)
        assert(!qu.isEmpty())
    }
}
