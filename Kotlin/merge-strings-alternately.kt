class Solution {
    fun mergeAlternately(word1: String, word2: String): String {
        val m = word1.length
        val n = word2.length
        val merged = StringBuilder(m + n)
        var i = 0
        val minLen = minOf(m, n)
        while (i < minLen) {
            merged.append(word1[i])
            merged.append(word2[i++])
        }
        if (i < m) {
            merged.append(word1, i, m)
        }
        if (i < n) {
            merged.append(word2, i, n)
        }
        return merged.toString()
    }
}