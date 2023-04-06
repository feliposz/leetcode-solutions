class Solution {
    fun closedIsland(grid: Array<IntArray>): Int {
        val height = grid.size
        val width = grid[0].size
        var islandCount = 0
        for (row in 0 until height) {
            for (col in 0 until width) {
                if (grid[row][col] == 0) {
                    if (!fillAndTestBorder(row, col, height, width, grid)) {
                        islandCount++
                    }
                }
            }
        }
        return islandCount
    }

    fun fillAndTestBorder(row: Int, col: Int, height: Int, width: Int, grid: Array<IntArray>) : Boolean {
        if (grid[row][col] != 0) {
            return false
        }
        grid[row][col] = 2 // mark as filled

        val testUp = (row < 1) || fillAndTestBorder(row - 1, col, height, width, grid)
        val testDn = (row >= height - 1) || fillAndTestBorder(row + 1, col, height, width, grid)
        val testLt = (col < 1) || fillAndTestBorder(row, col - 1, height, width, grid)
        val testRt = (col >= width - 1) || fillAndTestBorder(row, col + 1, height, width, grid)
        return testUp || testDn || testLt || testRt
    }
}