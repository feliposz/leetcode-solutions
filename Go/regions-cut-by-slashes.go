func regionsBySlashes(grid []string) int {
	id := 1

	rows := len(grid)
	cols := len(grid[0])

	m := make([][]int, rows*3)

	for i := range m {
		m[i] = make([]int, cols*3)
	}

	for r := range grid {
		for c := range grid[r] {
			if grid[r][c] == '/' {
				for i := 0; i < 3; i++ {
					m[r*3+i][c*3+2-i] = -1
				}
			} else if grid[r][c] == '\\' {
				for i := 0; i < 3; i++ {
					m[r*3+i][c*3+i] = -1
				}
			}
		}
	}

	for r := range m {
		for c := range m[r] {
			paint(m, r, c, id)
			id++
		}
	}

	unique := map[int]bool{}
	for r := range m {
		for _, val := range m[r] {
			if val >= 1 {
				unique[val] = true
			}
		}
	}

	return len(unique)
}

func paint(m [][]int, r, c, id int) {
	if m[r][c] != 0 {
		return
	}
	m[r][c] = id
	if r > 0 {
		paint(m, r-1, c, id)
	}
	if r < len(m)-1 {
		paint(m, r+1, c, id)
	}
	if c > 0 {
		paint(m, r, c-1, id)
	}
	if c < len(m[0])-1 {
		paint(m, r, c+1, id)
	}
}
