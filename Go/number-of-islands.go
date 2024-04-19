func numIslands(grid [][]byte) int {
    count := 0
    for i := range grid {
        for j := range grid[i] {
            if grid[i][j] == '1' {
                count++
                paint(grid, i, j)
            }
        }
    }
    return count
}

func paint(grid [][]byte, i, j int) {
    if i < 0 || j < 0 || i >= len(grid) || j >= len(grid[0]) {
        return
    }
    if grid[i][j] != '1' {
        return
    }
    grid[i][j] = '0'
    paint(grid, i - 1, j)
    paint(grid, i + 1, j)
    paint(grid, i, j - 1)
    paint(grid, i, j + 1)
}