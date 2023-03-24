/**
 * Example:
 * var ti = Node(5)
 * var v = ti.`val`
 * Definition for a Node.
 * class Node(var `val`: Int) {
 *     var next: Node? = null
 *     var random: Node? = null
 * }
 */

class Solution {
    fun copyRandomList(node: Node?): Node? {
        if (node == null) {
            return null
        }
        val map = mutableMapOf<Int,Node>()
        var curr: Node? = node
        while (curr != null) {
            val newNode = Node(curr.`val`)
            newNode.next = curr.next
            newNode.random = curr.random
            map[curr.hashCode()] = newNode
            curr = curr.next
        }
        var result = map[node.hashCode()]
        curr = result
        while (curr != null) {
            if (curr.next != null)
                curr.next = map[curr.next.hashCode()]
            if (curr.random != null)
                curr.random = map[curr.random.hashCode()]
            curr = curr.next
        }        
        return result
    }
}