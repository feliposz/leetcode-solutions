/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */
class Solution {
    fun reorderList(head: ListNode?): Unit {
        if (head == null) {
            return
        }
        var elements = mutableListOf<ListNode>()        
        var node = head
        while (node != null) {
            val next = node.next
            node.next = null
            elements.add(node)
            node = next
        }
        var i = 0
        var j = elements.size - 1
        while (i < j) {
            elements[i++].next = elements[j]
            if (i < j)
                elements[j--].next = elements[i]
        }
    }
}