func getMaximumGold(grid [][]int) int {
	maxGold := 0
	visited := make([][]bool, len(grid))
	for i := range visited {
		visited[i] = make([]bool, len(grid[0]))
	}
	for i := range grid {
		for j := range grid[i] {
			gold := collectGold(grid, i, j, visited)
			maxGold = max(maxGold, gold)
		}
	}
	return maxGold
}

func collectGold(grid [][]int, i int, j int, visited [][]bool) int {
	if i < 0 || j < 0 || i >= len(grid) || j >= len(grid[0]) || visited[i][j] || grid[i][j] == 0 {
		return 0
	}
	gold := grid[i][j]
	visited[i][j] = true
	up := collectGold(grid, i-1, j, visited)
	down := collectGold(grid, i+1, j, visited)
	left := collectGold(grid, i, j-1, visited)
	right := collectGold(grid, i, j+1, visited)
	visited[i][j] = false
	return gold + max(up, down, left, right)
}