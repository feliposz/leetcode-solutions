class Solution {
    fun lengthOfLastWord(s: String): Int {
        var t = s.trim()
        val p = t.indexOfLast({c -> c == ' '})
        return if (p == -1) t.length else t.length - p - 1
    }
}