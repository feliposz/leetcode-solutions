class NumMatrix(matrix: Array<IntArray>) {

    private var acc = matrix

    init {
        for (i in acc.indices) {
            for (j in acc[i].indices) {
                if (i > 0) {
                    acc[i][j] += acc[i-1][j]
                } 
                if (j > 0) {
                    acc[i][j] += acc[i][j-1]
                }
                if (i > 0 && j > 0) {
                    acc[i][j] -= acc[i-1][j-1]
                }
            }
        }
    }

    fun sumRegion(row1: Int, col1: Int, row2: Int, col2: Int): Int {
        var result = acc[row2][col2]
        if (row1 > 0) {
            result -= acc[row1-1][col2]
        }
        if (col1 > 0) {
            result -= acc[row2][col1-1]
        }
        if (row1 > 0 && col1 > 0) {
            result += acc[row1-1][col1-1]
        }
        return result
    }

}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * var obj = NumMatrix(matrix)
 * var param_1 = obj.sumRegion(row1,col1,row2,col2)
 */