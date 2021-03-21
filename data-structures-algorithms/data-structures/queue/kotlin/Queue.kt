/**
 * Queue implementation.
 *
 * Author : Lajos Neto.
 * Email : lajosnetogit@gmail.com
 */

data class Node<T>(
    val value:T,
    var next: Node<T>? = null
)

class Queue<T>{
    private var size = 0
    private var head: Node<T>? = null
    private var tail: Node<T>? = null

    override fun toString(): String {
        var stringRep = ""
        var walker = head
        while (walker != null) {
            stringRep += "${walker.value} -> "
            walker = walker.next
        }
        return "${stringRep}/null"
    }

    fun enqueue(value: T) {
        val newNode = Node(value)
        if (isEmpty()) {
            head = newNode
            tail = newNode
            size += 1
        } else {
            tail?.next = newNode
            tail = newNode
            size += 1
        }
    }

    fun dequeue() {
        if (!isEmpty()) {
            if (size == 1) {
                head = null
                tail == null
            } else {
                head = head?.next
                size -= 1
            }
        }
    }

    fun front() = head?.value
    fun isEmpty() = size == 0
    fun size() = size
}