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
    fun rotateRight(head: ListNode?, k: Int): ListNode? {
        if (k == 0 || head == null || head.next == null) {
            return head
        }
        val tmp = mutableListOf<ListNode?>()
        var n = head
        while (n != null) {
            tmp.add(n)
            n = n.next
        }
        if (k % tmp.size == 0) {
            return head
        }
        val split = tmp.size - k % tmp.size
        tmp[split-1]!!.next = null
        tmp.last()!!.next = head        
        return  tmp[split]
    }
}