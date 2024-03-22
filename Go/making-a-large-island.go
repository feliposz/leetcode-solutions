func largestIsland(grid [][]int) int {
	n := len(grid)

	// identify each island with a unique id and measure its size
	id := 2
	islandSizes := make(map[int]int)
	maxSize := 0
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 1 {
				size := paintIsland(grid, i, j, id)
				maxSize = max(maxSize, size)
				islandSizes[id] = size
				id++
			}
		}
	}

	if maxSize+1 >= n*n { // early return if island fills entire grid
		return n * n
	}

	// look for empty cells
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 0 {
				// set of the neighbors of the empty cell
				neighborIds := make(map[int]bool)
				if i > 0 {
					neighborIds[grid[i-1][j]] = true
				}
				if i < n-1 {
					neighborIds[grid[i+1][j]] = true
				}
				if j > 0 {
					neighborIds[grid[i][j-1]] = true
				}
				if j < n-1 {
					neighborIds[grid[i][j+1]] = true
				}
				size := 1 // the empty cell
				for id := range neighborIds {
					size += islandSizes[id]
				}
				maxSize = max(maxSize, size)
			}
		}
	}

	// for i := range grid {
	// 	fmt.Printf("%v\n", grid[i])
	// }

	return maxSize
}

// flood fill and count units
func paintIsland(grid [][]int, i, j, id int) int {
	if grid[i][j] != 1 {
		return 0
	}
	grid[i][j] = id
	size := 1
	n := len(grid)
	if i > 0 {
		size += paintIsland(grid, i-1, j, id)
	}
	if i < n-1 {
		size += paintIsland(grid, i+1, j, id)
	}
	if j > 0 {
		size += paintIsland(grid, i, j-1, id)
	}
	if j < n-1 {
		size += paintIsland(grid, i, j+1, id)
	}
	return size
}