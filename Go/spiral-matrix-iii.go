func spiralMatrixIII(rows int, cols int, rStart int, cStart int) [][]int {
	visited := make([][]int, rows*cols)
	moves := [][2]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}
	currMove := 0
	index := 0
	r, c := rStart, cStart
	nextCountDown := 1
	currCountDown := nextCountDown
	horizontalMove := true
	for index < len(visited) {
		// fmt.Println(r, c)
		if r >= 0 && r < rows && c >= 0 && c < cols {
			visited[index] = []int{r, c}
			index++
		}
		r += moves[currMove][0]
		c += moves[currMove][1]
		currCountDown--
		if currCountDown == 0 {
			horizontalMove = !horizontalMove
			if horizontalMove {
				nextCountDown++
			}
			currMove = (currMove + 1) % len(moves)
			currCountDown = nextCountDown
		}
	}
	return visited
}