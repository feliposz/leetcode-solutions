/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */
class Solution(private val head: ListNode?) {

    fun getRandom(): Int {
        var rnd = kotlin.random.Random
        var count = 0
        var node = head
        if (node == null) {
            return -1
        }
        var result = node.`val`
        while (node != null) {
            count++
            if (0 == rnd.nextInt(count)) {
                result = node.`val`
            }
            node = node?.next
        }
        return result
    }

}

/**
 * Your Solution object will be instantiated and called as such:
 * var obj = Solution(head)
 * var param_1 = obj.getRandom()
 */