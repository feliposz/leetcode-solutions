class Solution {
    fun arraySign(nums: IntArray): Int {
        var sign = 1
        for (n in nums) {
            if (n == 0)
                return 0
            if (n < 0)
                sign = -sign
        }
        return sign
    }
}