class Solution {
    fun multiply(num1: String, num2: String): String {
        val n1 = num1.length
        val n2 = num2.length
        var tmp = IntArray(n1 + n2)
        for (i in 0 until n1) {
            for (j in 0 until n2) {
                tmp[i+j+1] += (num1[i] - '0') * (num2[j] - '0')
            }
        }
        var carry = 0
        for (i in tmp.size - 1 downTo 0) {
            tmp[i] += carry
            carry = tmp[i] / 10
            tmp[i] %= 10
        }
        var i = 0
        while (i < tmp.size && tmp[i] == 0) {
            i++
        }
        var ans = ""
        while (i < tmp.size) {
            ans += tmp[i].toString()
            i++
        }
        return if (ans == "") "0" else ans
    }
}