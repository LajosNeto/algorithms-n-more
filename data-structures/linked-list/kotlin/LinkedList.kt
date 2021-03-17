/**
 * Linked List implementation.
 * 
 * Author : Lajos Neto.
 * Email : lajosnetogit@gmail.com
 */

data class Node<T>(
    val value: T,
    var next: Node<T>? = null
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
        if (isEmpty()) initialLoad(value)
        else {
            val newNode = Node(value, null)
            newNode.next = head
            head = newNode
        }
        size += 1
    }

    fun add(value: T, index: Int) {
        if (isEmpty() || index == 0) addBegin(value)
        else if (index in 0 until size()) {
            val newNode = Node(value)
            var walker = head
            for (i in 0 until index - 1) walker = walker?.next
            newNode.next = walker?.next
            walker?.next = newNode
            size += 1
        }
    }

    fun removeBegin() {
        if (!isEmpty()) {
            if (size() == 1) {
                head = null
                tail = null
            } else {
                head = head?.next
                size -= 1
            }
        }
    }

    fun addEnd(value: T) {
        if (isEmpty()) initialLoad(value)
        else {
            val newNode = Node(value, null)
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
            size -= 1
        }
    }

    fun front() = this.head?.value
    fun back() = this.tail?.value
    fun print() = this.toString()
    fun size() = size
    private fun isEmpty() = size == 0

    private fun initialLoad(value: T) {
        val newNode = Node(value)
        head = newNode
        tail = newNode
        size += 1
    }
}