class Solution {
    fun plusOne(digits: IntArray): IntArray {
        var n = digits.size-1
        var tmp: MutableList<Int> = digits.toMutableList()
        var carry = 1
        for (i in n downTo 0) {
            tmp[i] += carry
            carry = tmp[i] / 10
            tmp[i] %= 10
        }
        if (carry > 0) {
            tmp.add(0, carry)
        }
        return tmp.toIntArray()
    }
}