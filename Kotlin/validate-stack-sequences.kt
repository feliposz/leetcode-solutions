class Solution {
    fun validateStackSequences(pushed: IntArray, popped: IntArray): Boolean {
        var i = 0
        var j = 0
        val m = pushed.size
        val n = popped.size
        val stack = Stack<Int>()
        for (i in 0 until m) {
            stack.push(pushed[i])
            while (stack.isNotEmpty() && stack.peek() == popped[j]) {
                stack.pop()
                j++
                if (j == n) {
                    return true
                }
            }
        }
        return false
    }
}