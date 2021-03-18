/**
 * Stack implementation.
 *
 * Author : Lajos Neto.
 * Email : lajosnetogit@gmail.com
 */

data class Node<T>(
    val value:T,
    var next: Node<T>? = null
)

class Stack<T>{
    private var size = 0
    private var head: Node<T>? = null

    override fun toString(): String {
        var stringRep = ""
        var walker = head
        while (walker != null) {
            stringRep += "${walker.value} -> "
            walker = walker.next
        }
        return "${stringRep}/null"
    }

    fun push(value: T) {
        val newNode = Node(value)
        newNode.next = head
        head = newNode
        size += 1
    }

    fun pop() {
        if (!isEmpty()) {
            head = head?.next
            size -= 1
        }
    }

    fun top() = head?.value
    fun isEmpty() = size == 0
    fun size() = size
}