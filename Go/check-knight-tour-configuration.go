func checkValidGrid(grid [][]int) bool {
	size := len(grid)
	goal := size*size - 1
	next := 1
	x, y := 0, 0
	if grid[x][y] != 0 {
		return false
	}
	moves := [][]int{{-2, -1}, {2, -1}, {-2, 1}, {2, 1}, {-1, -2}, {1, -2}, {-1, 2}, {1, 2}}
	for next <= goal {
		found := false
		for _, move := range moves {
			x2, y2 := x+move[0], y+move[1]
			if x2 >= 0 && x2 < size && y2 >= 0 && y2 < size {
				if grid[x2][y2] == next {
					next++
                    x, y = x2, y2
                    found = true
					break
				}
			}
		}
		if !found {
			return false
		}
	}
	return true
}