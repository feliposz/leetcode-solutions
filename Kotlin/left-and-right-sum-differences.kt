class Solution {
    fun leftRigthDifference(nums: IntArray): IntArray {
        val n = nums.size
        var left = IntArray(n)
        var right = IntArray(n)
        for (i in 1 until n) {
            left[i] = left[i-1] + nums[i-1]
            val j = n - 1 - i
            right[j] = right[j+1] + nums[j+1]
        }
        var ans = IntArray(n)
        for (i in 0 until n) {
            ans[i] = kotlin.math.abs(left[i] - right[i])
        }
        return ans
    }
}