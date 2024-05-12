func largestLocal(grid [][]int) [][]int {
    n := len(grid)
    result := make([][]int, n-2)
    for i := range result {
        result[i] = make([]int, n-2)
    }
    for i := 1; i < n - 1; i++ {
        for j := 1; j < n - 1; j++ {
            localMax := grid[i][j]
            for x := -1; x < 2; x++ {
                for y := -1; y < 2; y++ {
                    localMax = max(localMax, grid[i+y][j+x])
                }
            }
            result[i-1][j-1] = localMax
        }
    }
    return result
}