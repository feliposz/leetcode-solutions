class Solution {
    fun isMonotonic(nums: IntArray): Boolean {
        var i = 0
        val n = nums.size - 1
        var maybeIncreasing = true
        var maybeDecreasing = true
        while (i < n) {
            val j = i + 1
            if (nums[i] < nums[j]) {
                maybeDecreasing = false
                if (!maybeIncreasing) {
                    break
                }
            }
            if (nums[i] > nums[j]) {
                maybeIncreasing = false
                if (!maybeDecreasing) {
                    break
                }
            }
            i++
        }
        return maybeIncreasing || maybeDecreasing
    }
}