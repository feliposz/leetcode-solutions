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
    fun addTwoNumbers(l1: ListNode?, l2: ListNode?): ListNode? {

        // add digits in reverse order
        val s = ArrayList<Int>()
        var n1 = l1
        var n2 = l2
        var carry = 0
        while (n1 != null || n2 != null ) {
            var x = carry
            if (n1 != null) {
                x += n1.`val`
                n1 = n1.next
            }
            if (n2 != null) {
                x += n2.`val`
                n2 = n2.next
            }
            carry = x / 10
            s.add(x % 10)
        }
        if (carry > 0) {
            s.add(carry)
        }

        // build result by reversing s
        var result: ListNode? = null
        for (x in s.reversed()) {
            val n = ListNode(x)
            n.next = result
            result = n
        }

        return result
    }
}