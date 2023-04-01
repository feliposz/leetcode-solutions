class Solution {
    fun search(nums: IntArray, target: Int): Int {
        var lo = 0
        var hi = nums.size - 1
        while (lo <= hi) {
            val mid = (lo + hi) / 2
            if (target == nums[mid]) {
                return mid
            } else if (target < nums[mid]) {
                hi = mid - 1
            } else {
                lo = mid + 1
            }
        }
        return -1
    }
}