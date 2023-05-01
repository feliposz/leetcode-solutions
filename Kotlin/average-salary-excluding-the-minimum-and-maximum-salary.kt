class Solution {
    fun average(salary: IntArray): Double {
        var lo = salary[0]
        var hi = salary[0]
        var sum = 0.0
        for (n in salary) {
            sum += n
            if (lo > n)
                lo = n
            if (hi < n)
                hi = n
        }
        return (sum - lo - hi) / (salary.size - 2)
    }
}