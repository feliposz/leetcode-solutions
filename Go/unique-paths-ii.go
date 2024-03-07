func uniquePathsWithObstacles(obstacleGrid [][]int) int {
    m, n := len(obstacleGrid), len(obstacleGrid[0])
    paths := make([][]int, m)
    for i := 0; i < m; i++ {
        paths[i] = make([]int, n)
        for j := 0; j < n; j++ {
            if obstacleGrid[i][j] == 1 {
                paths[i][j] = 0
            } else if i == 0 && j == 0 {
                paths[i][j] = 1
            } else if i == 0 {
                paths[i][j] = paths[i][j-1]
            } else if j == 0 {
                paths[i][j] = paths[i-1][j]
            } else {
                paths[i][j] = paths[i-1][j] + paths[i][j-1]
            }
        }
    }
    return paths[m-1][n-1]
}