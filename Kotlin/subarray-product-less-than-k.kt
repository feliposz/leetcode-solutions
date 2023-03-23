class Solution {
    fun numSubarrayProductLessThanK(nums: IntArray, k: Int): Int {
        // no point checking product below zero
        if (k == 0) {
            return 0
        }
        var count = 0
        var prod = 1
        var left = 0
        // move the right index while the value is smaller than k
        for (right in nums.indices) {
            prod *= nums[right]
            // if product grows larger, shrink the left side
            while (left <= right && prod >= k) {
                prod /= nums[left++]
            }
            // accumulate on count the difference between left and right pointers (multiple sub-arrays)
            count += right - left + 1
        }
        return count
    }
}