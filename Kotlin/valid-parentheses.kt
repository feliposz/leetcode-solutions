class Solution {
    fun isValid(s: String): Boolean {
        val stack = ArrayDeque<Char>()
        for (c in s) {
            if (c == '(' || c == '[' || c == '{') {
                stack.add(when (c) { 
                    '(' -> ')'
                    '[' -> ']'
                    '{' -> '}'
                    else -> '*'
                })
            } else if (c == ')' || c == ']' || c == '}') {
                if (!stack.isEmpty() && stack.last() == c) 
                    stack.removeLast()
                else 
                    return false 
            }
        }
        return stack.isEmpty()
    }
}