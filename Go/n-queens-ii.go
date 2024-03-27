func totalNQueens(n int) int {
    // every position in "queens" represents a row
    // and each value represents the column position of the queen
    // note that only one queen can be place per row anyway!
    
    queens := make([]int, n)
    return solve(queens, 0, n)
}

func solve(queens []int, currentRow, size int) (solutions int) {
    // if was able to place all previous queens, add to solutions and return
    if currentRow == size {
        return 1
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
			solutions += solve(queens, currentRow + 1, size)
        }
    }
    return solutions
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}