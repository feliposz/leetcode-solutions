class Solution {
    fun findMiddleIndex(nums: IntArray): Int {
        var total = 0
        for (n in nums) {
            total += n
        }
        var left = 0
        for (i in 0 until nums.size) {
            var right = total - left - nums[i]
            if (left == right) {
                return i
            }
            left += nums[i]
        }
        return -1
    }
}