class Solution {
    fun bulbSwitch(n: Int): Int {
        var count = 0
        for (i in 1..n) {
            if (i*i <= n)
                count++
            else
                break
        }
        return count
    }
}