class Solution {
    fun checkArithmeticSubarrays(nums: IntArray, l: IntArray, r: IntArray): List<Boolean> {
        val len = nums.size
        val queries = l.size
        var answer = MutableList<Boolean>(0, {false})
        for (q in 0 until queries) {
            val subLen = r[q] - l[q] + 1
            var sub = IntArray(subLen) { i -> nums[i + l[q]] }
            sub.sort()
            val delta = sub[1] - sub[0]
            var valid = true
            for (i in 1 until subLen) {
                if (sub[i] - sub[i-1] != delta) {
                    valid = false
                    break
                }
            }
            answer.add(valid)
        }
        return answer.toList()
    }
}