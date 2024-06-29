func getAncestors(n int, edges [][]int) [][]int {
	adj := make([][]int, n)
	for _, e := range edges {
		from, to := e[0], e[1]
		adj[to] = append(adj[to], from)
	}
	res := make([][]int, n)
	for i := range res {
		ancestors := map[int]struct{}{}
		helper(i, adj, ancestors)
		for a := range ancestors {
			if a != i {
				res[i] = append(res[i], a)
			}
		}
		slices.Sort(res[i])
	}
	return res
}

func helper(curr int, adj [][]int, ancestors map[int]struct{}) {
	ancestors[curr] = struct{}{}
	for _, next := range adj[curr] {
		if _, found := ancestors[next]; !found {
			helper(next, adj, ancestors)
		}
	}
}