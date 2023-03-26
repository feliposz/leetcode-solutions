/**
 * Example:
 * var ti = TreeNode(5)
 * var v = ti.`val`
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */
class BSTIterator(root: TreeNode?) {

    private val stack = mutableListOf<TreeNode?>()

    init {
        advance(root)
    }

    private fun advance(node: TreeNode?) {
        var curr = node
        while (curr != null) {
            stack.add(curr)
            curr = curr.left
        }
    }

    fun next(): Int {
        if (!hasNext())
            return -1
        val node = stack.removeAt(stack.size - 1)
        advance(node?.right)
        return node!!.`val`
    }

    fun hasNext(): Boolean {
        return stack.size > 0
    }

}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * var obj = BSTIterator(root)
 * var param_1 = obj.next()
 * var param_2 = obj.hasNext()
 */