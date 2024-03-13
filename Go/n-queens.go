func solveNQueens(n int) [][]string {
    // every position in "queens" represents a row
    // and each value represents the column position of the queen
    // note that only one queen can be place per row anyway!
    queens := make([]int, n)
	// storage for generated solutions
    solutions := make([][]int, 0)
    solve(queens, 0, n, &solutions)
	// convert solutions to string representation
    result := make([][]string, len(solutions))
    for i, queens := range solutions {
        result[i] = make([]string, n)
        for row, column := range queens {
            s := []byte(".........")
            s[column] = 'Q'
            result[i][row] = string(s[:n])
        }
    }
    return result
}

func solve(queens []int, currentRow, size int, solutions *[][]int) {
    // if was able to place all previous queens, add to solutions and return
    if currentRow == size {
        *solutions = append(*solutions, slices.Clone(queens))
        return
    }
    for currentCol := 0; currentCol < size; currentCol++ {
        valid := true
        // check against all previous placed queens
        for otherRow, otherCol := range queens[:currentRow] {
            // don't place in same column or diagonals (no need to check rows)
            if currentCol == otherCol || abs(currentRow - otherRow) == abs(currentCol - otherCol) {
                valid = false
                break
            }
        }
        if valid {
			// place queen
			queens[currentRow] = currentCol
			solve(queens, currentRow + 1, size, solutions)
        }
    }
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}