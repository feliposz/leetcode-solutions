class Solution {
    fun nextGreaterElements(nums: IntArray): IntArray {
        val n = nums.size
        var ans = IntArray(n)
        for (i in 0 until n) {
            ans[i] = -1
            for (j in 1 until n) {
                val k = (i + j) % n
                if (nums[k] > nums[i]) {
                    ans[i] = nums[k]
                    break
                }
            }
        }
        return ans
    }
}