func findChampion(grid [][]int) int {
	winner := 0
	for i := range grid[0] {
		if i == winner {
			continue
		}
		if grid[winner][i] == 0 {
			winner = i
		}
	}
	return winner
}