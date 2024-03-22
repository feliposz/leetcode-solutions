func possibleBipartition(n int, dislikes [][]int) bool {
	adj := make([][]int, n)

	for _, d := range dislikes {
		d0, d1 := d[0]-1, d[1]-1
		adj[d0] = append(adj[d0], d1)
		adj[d1] = append(adj[d1], d0)
	}

	colors := make([]int, n)
	for i := 0; i < n; i++ {
		if colors[i] == 0 && !paintGraph(i, adj, 1, colors) {
			return false
		}
	}
	return true
}

func paintGraph(start int, adj [][]int, fill int, colors []int) bool {
	colors[start] = fill
	for _, neighbor := range adj[start] {
		if colors[start] == colors[neighbor] {
			return false
		}
		if colors[neighbor] == 0 {
			otherFill := 3 - fill
			if !paintGraph(neighbor, adj, otherFill, colors) {
				return false
			}
		}
	}
	return true
}