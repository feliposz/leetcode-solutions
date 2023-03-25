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
        val m1 = ArrayList<Int>()
        val m2 = ArrayList<Int>()

        // convert digits to list in reverse order
        var n = l1
        while (n != null) {
            m1.add(n.`val`)
            n = n.next
        }
        n = l2
        while (n != null) {
            m2.add(n.`val`)
            n = n.next
        }

        // add digits in reverse order
        val s = ArrayList<Int>()
        var i1 = m1.size - 1
        var i2 = m2.size - 1
        var carry = 0
        while (i1 >= 0 || i2 >= 0) {
            var x = carry
            if (i1 >= 0)
                x += m1[i1--]
            if (i2 >= 0)
                x += m2[i2--]
            carry = x / 10
            s.add(x % 10)
        }
        if (carry > 0) {
            s.add(carry)
        }

        // build result by reversing s
        var result: ListNode? = null
        for (x in s) {
            val n = ListNode(x)
            n.next = result
            result = n
        }

        return result
    }
}