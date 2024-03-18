func getSkyline(buildings [][]int) [][]int {
	positions := make([]int, 0, len(buildings)*2)
	for _, b := range buildings {
		positions = append(positions, b[0], b[1])
	}
	slices.Sort(positions)
	prevPos, prevHeight := -1, -1
	result := [][]int{}
	for _, pos := range positions {
		if pos == prevPos {
			continue
		}
		maxHeight := 0
		for i := 0; i < len(buildings); i++ {
			if pos >= buildings[i][0] && pos < buildings[i][1] {
				maxHeight = max(maxHeight, buildings[i][2])
			}
		}
		if prevHeight != maxHeight {
			result = append(result, []int{pos, maxHeight})
		}
		prevPos, prevHeight = pos, maxHeight
	}
	return result
}