class Solution {
    fun spiralOrder(matrix: Array<IntArray>): List<Int> {
        val ans = MutableList<Int>(0, {0})
        
        var row1 = 0
        var row2 = matrix.size - 1;
        var col1 = 0
        var col2 = matrix[0].size - 1;
        
        while ((col1 < col2) && (row1 < row2)) {
            for (c in col1 until col2) {
                ans.add(matrix[row1][c]);
            }
            for (r in row1 until row2) {
                ans.add(matrix[r][col2]);
            }
            for (c in col2 downTo col1+1) {
                ans.add(matrix[row2][c]);
            }
            for (r in row2 downTo row1+1) {
                ans.add(matrix[r][col1]);
            }
            col1++;
            col2--;
            row1++;            
            row2--;
        }
        
        if (col1 == col2) {
            for (r in row1..row2) {
                ans.add(matrix[r][col1]);
            }            
        } else if (row1 == row2) {
            for (c in col1..col2) {
                ans.add(matrix[row1][c]);
            }
        }
        
        return ans.toList();        
    }
}