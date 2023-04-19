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
class Solution {
    fun longestZigZag(root: TreeNode?): Int {
        return zz(root, 0, 0)
    }

    fun zz(root: TreeNode?, dir: Int, len: Int): Int {
        if (root == null)
            return len
        val left = zz(root.left, -1, if (dir == 1) 1 + len else 0) 
        val right = zz(root.right, 1, if (dir == -1) 1 + len else 0)
        return maxOf(left, right)
    }
}