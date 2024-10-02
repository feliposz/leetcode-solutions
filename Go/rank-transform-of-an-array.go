func arrayRankTransform(arr []int) []int {
	if len(arr) == 0 {
		return arr
	}
	sorted := slices.Clone(arr)
	slices.Sort(sorted)
	ranks := map[int]int{}
	rank := 0
	prev := sorted[0] - 1
	for _, x := range sorted {
		if prev != x {
			rank++
		}
		ranks[x] = rank
		prev = x
	}
	for i, x := range arr {
		sorted[i] = ranks[x]
	}
	return sorted
}