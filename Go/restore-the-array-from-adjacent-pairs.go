func restoreArray(adjacentPairs [][]int) []int {
	adj := map[int][]int{}
	for _, pair := range adjacentPairs {
		adj[pair[0]] = append(adj[pair[0]], pair[1])
		adj[pair[1]] = append(adj[pair[1]], pair[0])
	}
	first := 0
	for i := range adj {
		if len(adj[i]) == 1 {
			first = i
			break
		}
	}
	curr := first
	prev := 999999999
	ans := make([]int, 0, len(adj))
	for {
		ans = append(ans, curr)
		foundNext := false
		for _, next := range adj[curr] {
			if next != prev {
				prev = curr
				curr = next
				foundNext = true
				break
			}
		}
		if !foundNext {
			break
		}
	}
	return ans
}