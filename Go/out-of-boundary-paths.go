func findPaths(m int, n int, maxMove int, row int, col int) int {
	prev := make2d(m, n)
	curr := make2d(m, n)
	prev[row][col] = 1 // set initial cell
	count := 0
	for moves := 1; moves <= maxMove; moves++ {
		for i := range prev {
			for j := range prev[i] {
				// count only border reached
				if i == 0 {
					count += prev[i][j]
				}
				if i == m-1 {
					count += prev[i][j]
				}
				if j == 0 {
					count += prev[i][j]
				}
				if j == n-1 {
					count += prev[i][j]
				}
				count %= 1_000_000_007

				curr[i][j] = 0 // must reset value, because of swap below

				// expand around the move cells
				if i > 0 {
					curr[i][j] += prev[i-1][j]
				}
				if i < m-1 {
					curr[i][j] += prev[i+1][j]
				}
				if j > 0 {
					curr[i][j] += prev[i][j-1]
				}
				if j < n-1 {
					curr[i][j] += prev[i][j+1]
				}
				curr[i][j] %= 1_000_000_007
			}
		}
		// swap current and previous to reuse alloc'd memory
		curr, prev = prev, curr
	}
	return count
}

func make2d(m, n int) [][]int {
	grid := make([][]int, m)
	for i := range grid {
		grid[i] = make([]int, n)
	}
	return grid
}