//data class Node(
//    val value: Number,
//    var left: Node? = null,
//    var right: Node? = null,
//    var parent: Node? = null,
//    var subtreeSize: Int = 0
//)
//
//class Bst {
//    private var root: Node? = null
//    private var size = 0
//
//    fun put(value: Number) {
//        root = _put(value, null, root)
//    }
//
//    private fun _put(value: Number, parentNode: Node?, currentNode: Node?): Node {
//        currentNode ?: return Node(value, parent = parentNode)
//        if (value.isSmaller(currentNode.value) == true)
//            currentNode.left = _put(value, currentNode, currentNode.left)
//        if (value.isBigger(currentNode.value) == true)
//            currentNode.right = _put(value, currentNode, currentNode.right)
//        return currentNode
//    }
//
//    fun getInOrder() = mutableListOf<Number>().apply { dfsInOrder(root, this) }
//
//    private fun dfsInOrder(currentNode: Node?, nodes: MutableList<Number>) {
//        currentNode?.let {
//            dfsInOrder(currentNode.left, nodes)
//            nodes.add(currentNode.value)
//            dfsInOrder(currentNode.right, nodes)
//        }
//    }
//
//    fun getPreOrder() = mutableListOf<Number>().apply { dfsPreOrder(root, this) }
//
//    private fun dfsPreOrder(currentNode: Node?, nodes: MutableList<Number>) {
//        currentNode?.let {
//            nodes.add(currentNode.value)
//            dfsPreOrder(currentNode.left, nodes)
//            dfsPreOrder(currentNode.right, nodes)
//        }
//    }
//
//    fun getPostOrder() = mutableListOf<Number>().apply { dfsPostOrder(root, this) }
//
//    private fun dfsPostOrder(currentNode: Node?, nodes: MutableList<Number>) {
//        currentNode?.let {
//            dfsPostOrder(currentNode.left, nodes)
//            dfsPostOrder(currentNode.right, nodes)
//            nodes.add(currentNode.value)
//        }
//    }
//
//    fun getBfsOrder() = mutableListOf<Number>().apply { bfsOrder(root, this) }
//
//    private fun bfsOrder(root: Node?, nodes: MutableList<Number>) {
//        root?.let {
//            val nodeQueue = mutableListOf(root)
//            while (nodeQueue.isNotEmpty()) {
//                nodeQueue.last().left?.let { leftNode -> nodeQueue.add(0, leftNode) }
//                nodeQueue.last().right?.let { rightNode -> nodeQueue.add(0, rightNode) }
//                nodes.add(nodeQueue.last().value)
//                nodeQueue.removeLast()
//            }
//        }
//    }
//
//    fun getIncreaseOrder() = getInOrder()
//
//    fun min() = min(root)
//
//    private fun min(node: Node?): Number? {
//        return if (node?.left != null) min(node.left)
//        else node?.value
//    }
//
//    fun max() = max(root)
//
//    private fun max(node: Node?): Number? {
//        return if (node?.right != null) max(node.right)
//        else node?.value
//    }
//
//    fun has(value: Number) = getNode(value, root) != null
//
//    fun parent(value: Number) = getNode(value, root)?.parent?.copy()
//
//    private fun getNode(value: Number, node: Node?): Node? {
//        return when {
//            value.isSmaller(node?.value) == true -> {
//                if (node?.left != null) getNode(value, node.left)
//                else null
//            }
//            value.isBigger(node?.value) == true -> {
//                if (node?.right != null) getNode(value, node.right)
//                else null
//            }
//            else -> { node }
//        }
//    }
//
//    fun size() = size
//
//    companion object {
//        fun Number.isSmaller(value: Number?) = value?.toLong()?.let { this.toLong() < it }
//        fun Number.isBigger(value: Number?) = value?.toLong()?.let { this.toLong() > it }
//    }
//}