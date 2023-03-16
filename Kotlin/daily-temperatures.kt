class Solution {
    fun dailyTemperatures(temperatures: IntArray): IntArray {
        val n = temperatures.size
        var ans = IntArray(n)
        for (i in 0 until n) {
            for (j in i + 1 until n) {
                if (temperatures[i] < temperatures[j]) {
                    ans[i] = j - i
                    break
                }
            }
        }
        return ans
    }
}