class Solution {
    fun strStr(haystack: String, needle: String): Int {
        val n = needle.length
        val m = haystack.length - n

        for (i in 0..m) {
            var found = true
            for (j in 0..n-1) {
                if (haystack[i+j] != needle[j]) {
                    found = false
                    break;
                }
            }
            if (found) {
                return i
            }
        }
        
        return -1
    }
}