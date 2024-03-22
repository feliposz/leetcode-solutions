func countSubIslands(grid1 [][]int, grid2 [][]int) int {
	m, n := len(grid1), len(grid1[0])
	id := 2
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid1[i][j] == 1 {
				// using it just for the side-effect on this pass
				_ = checkSubIsland(grid1, grid1, i, j, id)
				id++
			}
		}
	}

	// for i := range grid1 {
	//  	fmt.Printf("%v\n", grid1[i])
	// }

	subIslands := 0
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid2[i][j] == 1 && grid1[i][j] > 0 {
				if checkSubIsland(grid1, grid2, i, j, grid1[i][j]) {
					//fmt.Println(i, j, grid1[i][j], grid2[i][j])
					subIslands++
				}
			}
		}
	}

	// for i := range grid2 {
	//  	fmt.Printf("%v\n", grid2[i])
	// }

	return subIslands
}

func checkSubIsland(grid1 [][]int, grid2 [][]int, i, j, id int) bool {
	if grid2[i][j] != 1 {
		return true
	} else {
		grid2[i][j] = id
	}
	result := true
	if grid1[i][j] != id {
		result = false
	}
	m, n := len(grid1), len(grid1[0])
	if i > 0 && !checkSubIsland(grid1, grid2, i-1, j, id) {
		result = false
	}
	if i < m-1 && !checkSubIsland(grid1, grid2, i+1, j, id) {
		result = false
	}
	if j > 0 && !checkSubIsland(grid1, grid2, i, j-1, id) {
		result = false
	}
	if j < n-1 && !checkSubIsland(grid1, grid2, i, j+1, id) {
		result = false
	}
	return result
}
