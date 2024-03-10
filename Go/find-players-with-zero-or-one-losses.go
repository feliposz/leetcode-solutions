func findWinners(matches [][]int) [][]int {
	var winners, losers [100000]int
    n := len(matches)
	for i := 0; i < n; i++ {
		winners[matches[i][0]-1]++
		losers[matches[i][1]-1]++
	}
	noLosses := []int{}
	oneLoss := []int{}
    n = len(winners)
	for i := 0; i < 100000; i++ {
		if winners[i] > 0 && losers[i] == 0 {
			noLosses = append(noLosses, i+1)
		} else if losers[i] == 1 {
			oneLoss = append(oneLoss, i+1)
		}
	}
	return [][]int{noLosses, oneLoss}
}

/*
func findWinners_worse(matches [][]int) [][]int {
	winners := map[int]int{}
	losers := map[int]int{}
	for _, match := range matches {
		winners[match[0]-1]++
		losers[match[1]-1]++
	}
	noLosses := []int{}
	oneLoss := []int{}
	for i := range winners {
		if losers[i] == 0 {
			noLosses = append(noLosses, i+1)
		}
	}
	for i := range losers {
		if losers[i] == 1 {
			oneLoss = append(oneLoss, i+1)
		}
	}
	return [][]int{noLosses, oneLoss}
}
*/
