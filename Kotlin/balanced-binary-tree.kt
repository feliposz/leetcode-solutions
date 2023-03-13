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
    fun isBalanced(root: TreeNode?): Boolean {
        if (root == null) {
            return true
        }
        if (!isBalanced(root?.left)) {
            return false
        }
        if (!isBalanced(root?.right)) {
            return false
        }        
        var leftHeight = treeHeight(root?.left)
        var rightHeight = treeHeight(root?.right)
        var diff = kotlin.math.abs(leftHeight - rightHeight)
        return diff < 2
    }

    fun treeHeight(root: TreeNode?): Int {
        if (root != null) {
            var left = treeHeight(root?.left)
            var right = treeHeight(root?.right)
            return 1 + kotlin.math.max(left, right)
        }
        return 0
    }
}