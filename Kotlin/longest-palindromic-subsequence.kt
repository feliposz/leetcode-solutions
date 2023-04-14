class Solution {

    fun longestPalindromeSubseq(s: String): Int {
        val r = s.reversed()
        val n = s.length
        val dp = Array<IntArray>(n + 1, { IntArray(n + 1, {0}) })

        for (i in 1..n) {
            for (j in 1..n) {
                if (s[i-1] == r[j-1])
                    dp[i][j] =  1 + dp[i-1][j-1] 
                else 
                    dp[i][j] = kotlin.math.max(dp[i-1][j], dp[i][j-1])
            }
        }

        return dp.last().last()
    }
    
}