func checkXMatrix(grid [][]int) bool {
    n := len(grid)
    for i := 0; i < n; i++ {
        for j := 0; j < n; j++ {
            if grid[i][j] == 0 && (i == j || i == n - j - 1) {
                return false
            } else if grid[i][j] != 0 && i != j && i != n - j - 1 {
                return false
            }
        }
    }
    return true
}