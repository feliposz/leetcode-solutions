/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */
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
    fun isSubPath(head: ListNode?, root: TreeNode?): Boolean {
        if (head == null) {
            return true
        }
        if (root == null) {
            return false
        }
        return comparePath(head, root) || isSubPath(head, root?.left) || isSubPath(head, root?.right)
    }

    fun comparePath(head: ListNode?, root: TreeNode?): Boolean {
        if (head == null) {
            return true
        }
        if (root == null) {
            return false
        }
        return head.`val` == root.`val` && (comparePath(head?.next, root?.left) || comparePath(head?.next, root?.right))
    }
}