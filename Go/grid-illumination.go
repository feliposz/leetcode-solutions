func gridIllumination(n int, lamps [][]int, queries [][]int) []int {

	// hashmap of lamps
	mapRow := make(map[int]map[int]struct{})
	mapCol := make(map[int]map[int]struct{})
	mapD1 := make(map[int]map[[2]int]struct{})
	mapD2 := make(map[int]map[[2]int]struct{})

	for _, lamp := range lamps {

		row, col := lamp[0], lamp[1]
		d1, d2 := row+col, row-col

		if _, ok := mapRow[row]; !ok {
			mapRow[row] = make(map[int]struct{})
		}
		if _, ok := mapCol[col]; !ok {
			mapCol[col] = make(map[int]struct{})
		}
		if _, ok := mapD1[d1]; !ok {
			mapD1[d1] = make(map[[2]int]struct{})
		}
		if _, ok := mapD2[d2]; !ok {
			mapD2[d2] = make(map[[2]int]struct{})
		}

		coord := [2]int{row, col}

		mapRow[row][col] = struct{}{}
		mapCol[col][row] = struct{}{}
		mapD1[d1][coord] = struct{}{}
		mapD2[d2][coord] = struct{}{}
	}

	result := make([]int, 0, len(queries))

	for _, query := range queries {
		queryRow, queryCol := query[0], query[1]
		queryD1, queryD2 := queryRow+queryCol, queryRow-queryCol

		// check if lamp is on and at the same row, column or diagonal
		illuminated := 0
		if _, ok := mapRow[queryRow]; ok {
			illuminated = 1
		} else if _, ok := mapCol[queryCol]; ok {
			illuminated = 1
		} else if _, ok := mapD1[queryD1]; ok {
			illuminated = 1
		} else if _, ok := mapD2[queryD2]; ok {
			illuminated = 1
		}
		result = append(result, illuminated)

		// turn off lamps around query
		for deltaRow := -1; deltaRow <= 1; deltaRow++ {
			for deltaCol := -1; deltaCol <= 1; deltaCol++ {
				row, col := queryRow+deltaRow, queryCol+deltaCol

				if row >= 0 && row < n && col >= 0 && col < n {
					d1, d2 := row+col, row-col
					coord := [2]int{row, col}

					if _, ok := mapRow[row]; ok {
						delete(mapRow[row], col)
						if len(mapRow[row]) == 0 {
							delete(mapRow, row)
						}
					}

					if _, ok := mapCol[col]; ok {
						delete(mapCol[col], row)
						if len(mapCol[col]) == 0 {
							delete(mapCol, col)
						}
					}

					if _, ok := mapD1[d1]; ok {
						delete(mapD1[d1], coord)
						if len(mapD1[d1]) == 0 {
							delete(mapD1, d1)
						}
					}

					if _, ok := mapD2[d2]; ok {
						delete(mapD2[d2], coord)
						if len(mapD2[d2]) == 0 {
							delete(mapD2, d2)
						}
					}
				}
			}
		}
	}
	return result
}