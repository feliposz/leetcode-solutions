class Solution {
    fun numEnclaves(grid: Array<IntArray>): Int {
        val height = grid.size
        val width = grid[0].size

        // for every cell that is touching border if cell is 1, flood fill with 0

        for (col in 0 until width) {
            if (grid[0][col] == 1) 
                floodFill(0, col, height, width, grid)
            if (grid[height-1][col] == 1) 
                floodFill(height-1, col, height, width, grid)
        }
        for (row in 0 until height) {
            if (grid[row][0] == 1) 
                floodFill(row, 0, height, width, grid)
            if (grid[row][width-1] == 1) 
                floodFill(row, width-1, height, width, grid)                
        }

        // count remaining cells with value 1
        val count = grid.map { it.sum() }.sum()
        return count
    }

    fun floodFill(row: Int, col: Int, height: Int, width: Int, grid: Array<IntArray>) {
        if (grid[row][col] == 0) 
            return
        grid[row][col] = 0
        if (row > 1)
            floodFill(row-1, col, height, width, grid)
        if (row < height - 1)
            floodFill(row+1, col, height, width, grid)           
        if (col > 1)
            floodFill(row, col-1, height, width, grid)
        if (col < width - 1)
            floodFill(row, col+1, height, width, grid)
    }
}