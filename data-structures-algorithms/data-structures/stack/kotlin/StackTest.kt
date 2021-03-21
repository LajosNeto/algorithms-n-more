/**
 * Stack tests.
 *
 * Author : Lajos Neto.
 * Email : lajosnetogit@gmail.com
 */

import org.junit.Test

class StackTest {

    @Test
    fun pushTest() {
        val st = Stack<Int>()
        assert(st.toString() == "/null")
        st.push(10)
        assert(st.toString() == "10 -> /null")
        st.push(20)
        assert(st.toString() == "20 -> 10 -> /null")
        st.push(30)
        assert(st.toString() == "30 -> 20 -> 10 -> /null")
        st.push(40)
        assert(st.toString() == "40 -> 30 -> 20 -> 10 -> /null")
    }

    @Test
    fun popTest() {
        val st = Stack<Int>()
        st.push(10)
        st.push(20)
        st.push(30)
        st.push(40)
        st.pop()
        assert(st.toString() == "30 -> 20 -> 10 -> /null")
        st.pop()
        assert(st.toString() == "20 -> 10 -> /null")
        st.pop()
        assert(st.toString() == "10 -> /null")
        st.pop()
        assert(st.toString() == "/null")
    }

    @Test
    fun topTest() {
        val st = Stack<Int>()
        assert(st.top() == null)
        st.push(10)
        assert(st.top() == 10)
        st.push(20)
        assert(st.top() == 20)
        st.push(30)
        assert(st.top() == 30)
        st.push(40)
        assert(st.top() == 40)
    }

    @Test
    fun sizeTest() {
        val st = Stack<Int>()
        assert(st.size() == 0)
        st.push(10)
        assert(st.size() == 1)
        st.push(20)
        assert(st.size() == 2)
        st.push(30)
        assert(st.size() == 3)
        st.push(40)
        assert(st.size() == 4)
    }

    @Test
    fun isEmptyTest() {
        val st = Stack<Int>()
        assert(st.isEmpty())
        st.push(10)
        assert(!st.isEmpty())
    }
}
