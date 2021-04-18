/**
 * BST (Binary Search Tree) implementation.
 *
 * Author : Lajos Neto.
 * Email : lajosnetogit@gmail.com
 */

data class Node(
    val value: Number,
    var left: Node? = null,
    var right: Node? = null,
    var parent: Node? = null,
    var subtreeSize: Int = 0
)

class Bst {
    private lateinit var root: Node
    private var size = 0

    fun put(value: Number) {
        when (size) {
            0 -> {
                root = Node(value = value, subtreeSize = 1)
                size += 1
            }
            else -> { _put(value, root) }
        }
    }

    private fun _put(value: Number, currentNode: Node) {
        if (value.isSmaller(currentNode.value)) {
            when {
                currentNode.left != null -> {
                    currentNode.left?.let { _put(value, it) }
                }
                else -> {
                    currentNode.left = Node(value)
                    size += 1
                }
            }
        } else if (value.isBigger(currentNode.value)) {
            when {
                currentNode.right != null -> {
                    currentNode.right?.let { _put(value, it) }
                }
                else -> {
                    currentNode.right = Node(value)
                    size += 1
                }
            }
        }
    }

    fun getInOrder() { if (size > 0) { dfsInOrder(root) } }

    private fun dfsInOrder(currentNode: Node?) {
        currentNode?.let {
            dfsInOrder(currentNode.left)
            println(currentNode.value)
            dfsInOrder(currentNode.right)
        }
    }

    fun getPreOrder() { if (size > 0) { dfsPreOrder(root) } }

    private fun dfsPreOrder(currentNode: Node?) {
        currentNode?.let {
            println(currentNode.value)
            dfsPreOrder(currentNode.left)
            dfsPreOrder(currentNode.right)
        }
    }

    fun getPostOrder() { if (size > 0) { dfsPostOrder(root) } }

    private fun dfsPostOrder(currentNode: Node?) {
        currentNode?.let {
            dfsPostOrder(currentNode.left)
            dfsPostOrder(currentNode.right)
            println(currentNode.value)
        }
    }

    fun size() = size

    companion object {
        fun Number.isSmaller(value: Number) = this.toLong() < value.toLong()
        fun Number.isBigger(value: Number) = this.toLong() > value.toLong()
    }
}