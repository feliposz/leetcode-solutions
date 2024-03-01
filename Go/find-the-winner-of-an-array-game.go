func getWinner(arr []int, k int) int {
	streak := 0
	current := arr[0]
	for _, opponent := range arr[1:] {
		if current > opponent {
			streak++
		} else {
			current = opponent
			streak = 1
		}
		if streak == k {
			return current
		}
	}
	return current
}