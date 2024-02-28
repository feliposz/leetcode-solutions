func countUnguarded(m int, n int, guards [][]int, walls [][]int) int {
	grid := make([][]byte, m)
	for i := range grid {
		grid[i] = make([]byte, n)
	}
	for i := range guards {
		grid[guards[i][0]][guards[i][1]] = 'G'
	}
	for i := range walls {
		grid[walls[i][0]][walls[i][1]] = 'W'
	}
	directions := [][]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}
	for i := range guards {
		for j := range directions {
            x, y := guards[i][0]+directions[j][0], guards[i][1]+directions[j][1]
			for x >= 0 && x < m && y >= 0 && y < n {
				if grid[x][y] == 0 {
					grid[x][y] = '.'
				} else if grid[x][y] != '.' {
					break
				}
                x, y = x+directions[j][0], y+directions[j][1]
			}
		}
	}
	result := 0
	for x := range grid {
		for y := range grid[x] {
			//fmt.Printf("%c ", grid[i][j])
			if grid[x][y] == 0 {
				result++
			}
		}
		//fmt.Println()
	}
	return result
}
