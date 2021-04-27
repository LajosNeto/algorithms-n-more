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
    private var root: Node? = null
    private var size = 0

    fun put(value: Number) {
        root = _put(value, root)
    }

    private fun _put(value: Number, currentNode: Node?): Node {
        currentNode ?: return Node(value)
        if (value.isSmaller(currentNode.value) == true)
            currentNode.left = _put(value, currentNode.left)
        if (value.isBigger(currentNode.value) == true)
            currentNode.right = _put(value, currentNode.right)
        return currentNode
    }

    fun getInOrder() = mutableListOf<Number>().apply { dfsInOrder(root, this) }

    private fun dfsInOrder(currentNode: Node?, nodes: MutableList<Number>) {
        currentNode?.let {
            dfsInOrder(currentNode.left, nodes)
            nodes.add(currentNode.value)
            dfsInOrder(currentNode.right, nodes)
        }
    }

    fun getPreOrder() = mutableListOf<Number>().apply { dfsPreOrder(root, this) }

    private fun dfsPreOrder(currentNode: Node?, nodes: MutableList<Number>) {
        currentNode?.let {
            nodes.add(currentNode.value)
            dfsPreOrder(currentNode.left, nodes)
            dfsPreOrder(currentNode.right, nodes)
        }
    }

    fun getPostOrder() = mutableListOf<Number>().apply { dfsPostOrder(root, this) }

    private fun dfsPostOrder(currentNode: Node?, nodes: MutableList<Number>) {
        currentNode?.let {
            dfsPostOrder(currentNode.left, nodes)
            dfsPostOrder(currentNode.right, nodes)
            nodes.add(currentNode.value)
        }
    }

    fun getIncreaseOrder() = getInOrder()

    fun getBfsOrder() = mutableListOf<Number>().apply { bfsOrder(root, this) }

    private fun bfsOrder(root: Node?, nodes: MutableList<Number>) {
        root?.let {
            val nodeQueue = mutableListOf(root)
            while (nodeQueue.isNotEmpty()) {
                nodeQueue.last().left?.let { leftNode -> nodeQueue.add(0, leftNode) }
                nodeQueue.last().right?.let { rightNode -> nodeQueue.add(0, rightNode) }
                nodes.add(nodeQueue.last().value)
                nodeQueue.removeLast()
            }
        }

    }

    fun size() = size

    companion object {
        fun Number.isSmaller(value: Number?) = value?.toLong()?.let { this.toLong() < it }
        fun Number.isBigger(value: Number?) = value?.toLong()?.let { this.toLong() > it }
    }

}