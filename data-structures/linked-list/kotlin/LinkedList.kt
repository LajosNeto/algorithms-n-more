/**
 * Linked List implementation.
 * 
 * Author : Lajos Neto.
 * Email : lajosnetogit@gmail.com
 */

data class Node<T>(
    val value: T,
    var next: Node<T>?
)

class LinkedList<T> {
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

    fun addBegin(value: T) {
        val newNode = Node(value, null)
        if (isEmpty()) initialLoad(newNode)
        else {
            newNode.next = head
            head = newNode
        }
        size += 1
    }

    fun removeBegin() { if (!isEmpty()) head = head?.next }

    fun addEnd(value: T) {
        val newNode = Node(value, null)
        if (isEmpty()) initialLoad(newNode)
        else {
            tail?.next = newNode
            tail = newNode
        }
        size += 1
    }

    fun removeEnd() {
        if (!isEmpty()) {
            if (size() == 1) {
                head = null
                tail = null
            } else {
                var walker = head
                while (walker?.next?.next != null) walker = walker.next
                tail = walker
                tail?.next = null
            }
        }
    }

    fun front() = this.head?.value
    fun back() = this.tail?.value
    fun print() = this.toString()
    fun size() = size
    private fun isEmpty() = size == 0

    private fun initialLoad(newNode: Node<T>) {
        head = newNode
        tail = newNode
    }
}