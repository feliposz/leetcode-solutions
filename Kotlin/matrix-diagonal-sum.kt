class Solution {
    fun diagonalSum(mat: Array<IntArray>): Int {
        val n = mat.size
        var sum = 0
        for (i in 0 until n) {
            sum += mat[i][i] + mat[i][n - 1 - i]
        }
        if (n % 2 == 1)
            sum -= mat[n / 2][n / 2]        
        return sum
    }
}