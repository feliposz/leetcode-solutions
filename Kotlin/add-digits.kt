class Solution {
    fun addDigits(num: Int): Int {
        var tmp = num
        while (tmp >= 10) {
            var sum = 0
            while (tmp > 0) {
                sum += tmp % 10
                tmp /= 10
            }
            tmp = sum
        }
        return tmp
    }
}