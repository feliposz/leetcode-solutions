import kotlin.math.*

class Solution {
    fun smallestRangeII(nums: IntArray, k: Int): Int {

        nums.sort()

        var smallest = nums.first()
        var largest = nums.last()

        var range = largest - smallest

        for (i in 1 until nums.size) {
            val prev = nums[i-1]
            val curr = nums[i]
            range = min(range, max(largest - k, prev + k) - min(smallest + k, curr - k))
        }
        
        return range
    }
}