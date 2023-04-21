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
    
    class Node(var low: Long, var high: Long)

    val treeLevels = ArrayList<Node>()

    fun widthOfBinaryTree(root: TreeNode?): Int {
        traverse(root, 0, 0)
        var ans: Long = 0
        for (v in treeLevels) {
            ans = maxOf(ans, v.high - v.low + 1)
        }
        return ans.toInt()
    }

    fun traverse(root: TreeNode?, level: Int, pos: Long) {
        if (root == null) {
            return
        }
        if (level > treeLevels.size - 1) {
            treeLevels.add(Node(pos, pos))
        }
        treeLevels[level].low = minOf(treeLevels[level].low, pos)
        treeLevels[level].high = maxOf(treeLevels[level].high, pos)
        traverse(root.left, level + 1, 2 * pos)
        traverse(root.right, level + 1, 2 * pos + 1)
    }

}