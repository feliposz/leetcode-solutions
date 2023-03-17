class Solution {
    fun findRotation(mat: Array<IntArray>, target: Array<IntArray>): Boolean {
        var count = 4
        while (count > 0) {
            if (compare(mat, target)) {
                return true;
            }
            rotate(mat)            
            count--
        }
        return false
    }

    fun compare(mat: Array<IntArray>, target: Array<IntArray>): Boolean {
        var m = mat.size
        for (i in 0 until m) {
            for (j in 0 until m) {
                if (mat[i][j] != target[i][j]) {
                    return false
                }
            }
        }
        return true
    }

    fun rotate(matrix: Array<IntArray>): Unit {
        var m = matrix.size

        for (i in 0 until m) {
            for (j in 0 until i) {
                val tmp = matrix[i][j]
                matrix[i][j] = matrix[j][i]
                matrix[j][i] = tmp
            }
        }

        for (i in 0 until m) {
            for (j in 0 until m/2) {
                val tmp = matrix[i][j]
                matrix[i][j] = matrix[i][m-j-1]
                matrix[i][m-j-1] = tmp
            }
        }
    }    
}