class MinStack() {

    val stackVal = ArrayDeque<Int>()
    val stackMin = ArrayDeque<Int>()

    fun push(`val`: Int) {
        stackVal.push(`val`)
        val currMin = stackMin.peek() ?: `val`
        val newMin = if (`val` < currMin) `val` else currMin
        stackMin.push(newMin)
    }

    fun pop() {
        stackVal.pop()
        stackMin.pop()
    }

    fun top(): Int {
        return stackVal.peek()
    }

    fun getMin(): Int {
        return stackMin.peek()
    }

}

/**
 * Your MinStack object will be instantiated and called as such:
 * var obj = MinStack()
 * obj.push(`val`)
 * obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.getMin()
 */