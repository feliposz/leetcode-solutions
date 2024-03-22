func islandPerimeter(grid [][]int) int {
    rows, cols := len(grid), len(grid[0])

    perimeter := 0
    for i := 0; i <= rows; i++ {
        left := 0
        for j := 0; j <= cols; j++ {
            curr, up := 0, 0
            if j < cols {
                if i > 0 {
                    up = grid[i - 1][j]
                }
                if i < rows {
                    curr = grid[i][j]
                }
            }
            if curr != up {
                perimeter++
            }
            if curr != left {
                perimeter++
            }
            left = curr
        }
    }
    return perimeter
}