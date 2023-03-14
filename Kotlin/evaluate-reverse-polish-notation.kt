class Solution {
    var stack: MutableList<Int> = mutableListOf()
    
    fun evalRPN(tokens: Array<String>): Int {
        
        for (token in tokens) {
            when (token) {
                "+" -> push(pop() + pop())
                "*" -> push(pop() * pop())
                "-" -> { var x = pop(); push(pop() - x) }
                "/" -> { var x = pop(); push(pop() / x) }
                else -> push(token.toInt())
            }
        }

        return pop()
    }

    fun push(n: Int) {
        stack.add(n)
    }

    fun pop(): Int {
        var n = stack.last()
        stack.removeAt(stack.size - 1)
        return n
    }
}