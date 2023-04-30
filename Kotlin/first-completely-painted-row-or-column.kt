class Solution {
    fun firstCompleteIndex(arr: IntArray, mat: Array<IntArray>): Int {
        val m = mat.size
        val n = mat[0].size
        val sz = arr.size
        val matRows = IntArray(sz)
        val matCols = IntArray(sz)
        for ((i, row) in mat.withIndex()) {
            for ((j, col) in row.withIndex()) {
                matRows[col-1] = i
                matCols[col-1] = j
            }
        }
        val countRows = IntArray(sz, {0})
        val countCols = IntArray(sz, {0})
        for ((index, num) in arr.withIndex()) {
            val i = matRows[num-1]
            val j = matCols[num-1]
            if (++countRows[i] == n || ++countCols[j] == m) {
                return index
            }
        }
        return sz
    }
}