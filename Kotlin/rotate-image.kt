class Solution {
    fun rotate(matrix: Array<IntArray>): Unit {
        var m = matrix.size
        var n = matrix[0].size

        for (i in 0 until m) {
            for (j in 0 until n) {
                if (i > j) {
                    val tmp = matrix[i][j]
                    matrix[i][j] = matrix[j][i]
                    matrix[j][i] = tmp
                }
            }
        }

        for (i in 0 until m) {
            for (j in 0 until n/2) {
                val tmp = matrix[i][j]
                matrix[i][j] = matrix[i][n-j-1]
                matrix[i][n-j-1] = tmp
            }
        }
    }
}