class Solution {
    fun addToArrayForm(num: IntArray, k: Int): List<Int> {
        var i = num.size - 1
        var carry = k
        while (i >= 0) {
            num[i] += carry
            carry = num[i] / 10
            num[i] %= 10
            i--
        }
        if (carry > 0) {
            var ans = num.toMutableList()
            while (carry > 0) {
                ans.add(0, carry % 10)
                carry /= 10
            }
            return ans.toList()
        }
        return num.toList()
    }
}