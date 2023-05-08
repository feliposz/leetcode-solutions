class Solution {
    fun distinctDifferenceArray(nums: IntArray): IntArray {
        val pref = IntArray(50)
        val suff = IntArray(50)
        for (n in nums) {
            suff[n-1]++
        }
        val ans = IntArray(nums.size)
        for ((i, n) in nums.withIndex()) {
            pref[n-1]++
            suff[n-1]--
            ans[i] = pref.count { it > 0 } - suff.count { it > 0 }
        }
        return ans
    }
}