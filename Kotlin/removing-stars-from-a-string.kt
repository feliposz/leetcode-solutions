class Solution {
    fun removeStars(s: String): String {
        val result = ArrayDeque<Char>()
        for (c in s) {
            if (c == '*' && !result.isEmpty()) {
                result.removeLast()
            } else {
                result.addLast(c)
            }
        }
        return result.joinToString(separator = "")
    }
}