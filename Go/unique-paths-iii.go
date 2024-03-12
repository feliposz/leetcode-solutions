func uniquePathsIII(grid [][]int) int {
	var startX, startY int
	m, n := len(grid), len(grid[0])
	steps := m * n
	for i := range grid {
		for j, value := range grid[i] {
			switch value {
			case 1:
				startX, startY = j, i
			case -1:
				steps--
			}
		}
	}

	var countPaths func(grid [][]int, steps, x, y int) int

	countPaths = func(grid [][]int, steps, x, y int) int {
		if grid[y][x] < 0 || steps <= 0 {
			return 0
		}
		if steps == 1 {
			if grid[y][x] == 2 {
				//fmt.Println(grid)
				return 1
			} else {
				return 0
			}
		}
		count := 0
        old := grid[y][x]
		grid[y][x] = -1
		if y > 0 {
			count += countPaths(grid, steps-1, x, y-1)
		}
		if y < m-1 {
			count += countPaths(grid, steps-1, x, y+1)
		}
		if x > 0 {
			count += countPaths(grid, steps-1, x-1, y)
		}
		if x < n-1 {
			count += countPaths(grid, steps-1, x+1, y)
		}
        grid[y][x] = old
		return count
	}

	return countPaths(grid, steps, startX, startY)
}
