class Solution {
    fun maxVowels(s: String, k: Int): Int {
        var count = 0
        var maxCount = 0
        var left = 0
        var right = 0
        val vowels = "aeiou"
        while (right < s.length && right < k) {
            if (s[right++] in vowels) {
                count++                
            }
            if (maxCount < count) {
                maxCount = count
                if (maxCount == k) {
                   return maxCount
                }
            }
        }
        while (right < s.length) {
            if (s[left++] in vowels) {
                count-- 
            }
            if (s[right++] in vowels) {
                count++                
            }
            if (maxCount < count) {
                maxCount = count
                if (maxCount == k) {
                   break
                }
            }
        }
        return maxCount
    }
}