class Solution {
    fun numSubseq(nums: IntArray, target: Int): Int {
        nums.sort()
        val n = nums.size
        val modulo = 1_000_000_007
        var total = 0
        var j = n - 1
        for (i in 0 until n) {
            while (i <= j && nums[i] + nums[j] > target) {                    
                j--
            }
            if (i <= j && nums[i] + nums[j] <= target) {
                total = (total + power(2, j - i, modulo)) % modulo
            }
        }
        return total
    }

    fun power(base: Int, exp: Int, mod: Int): Int {
        var result = 1L
        var base2 = base.toLong()
        var exp2 = exp
        while (true) {
            if (exp2 % 2 == 1) {
                result = (result * base2) % mod
            } 
            exp2 /= 2
            if (exp2 == 0) {
                break
            }
            base2 = (base2 * base2) % mod
        }
        return result.toInt()
    }
}