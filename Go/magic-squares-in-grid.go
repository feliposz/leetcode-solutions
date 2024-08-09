func numMagicSquaresInside(grid [][]int) int {
	rows, cols := len(grid), len(grid[0])
	count := 0
	for top := 0; top < rows-2; top++ {
		for left := 0; left < cols-2; left++ {
			digits := [9]bool{}
			rowSum := [3]int{}
			colSum := [3]int{}
			d1Sum := 0
			d2Sum := 0
			// fmt.Println(top, left)
			for i := 0; i < 3; i++ {
				for j := 0; j < 3; j++ {
					cell := grid[top+i][left+j]
					if cell >= 1 && cell <= 9 {
						digits[cell-1] = true
					}
					// fmt.Print(cell, " ")
				}
				// fmt.Println()
			}
			valid := true
			for _, d := range digits {
				if d == false {
					valid = false
					break
				}
			}
			if !valid {
				continue
			}
			for i := 0; i < 3; i++ {
				for j := 0; j < 3; j++ {
					rowSum[i] += grid[top+i][left+j]
					colSum[i] += grid[top+j][left+i]
				}
				d1Sum += grid[top+i][left+i]
				d2Sum += grid[top+i][left+2-i]
			}
			for i := 0; i < 3; i++ {
				if rowSum[i] != 15 || colSum[i] != 15 || d1Sum != 15 || d2Sum != 15 {
					valid = false
					break
				}
			}
			// fmt.Println(rowSum, colSum, d1Sum, d2Sum)
			if valid {
				count++
			}
		}
	}
	return count
}