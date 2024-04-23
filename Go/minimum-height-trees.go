func findMinHeightTrees(n int, edges [][]int) []int {
	if n == 1 {
		return []int{0}
	}

	// build adjacency list
	adj := make([][]int, n)
	for _, e := range edges {
		adj[e[0]] = append(adj[e[0]], e[1])
		adj[e[1]] = append(adj[e[1]], e[0])
	}

	// find the leaves of the tree (nodes with only a single neighbor)
	leaves := []int{}
	for i, neighbors := range adj {
		if len(neighbors) == 1 {
			leaves = append(leaves, i)
		}
	}

	// iteratively remove the leaves from their adjacent neighbor
	for n > 2 {
		// "pretend" we already removed the leaves from the graph
		n -= len(leaves)
		// next set of leaves for the next iteration
		newLeaves := []int{}
		for _, curr := range leaves {
			// leaves only have a single neighbor
			onlyNeighbor := adj[curr][0]
			// remove the current leave from the neighbors adjacency list
			lastIndex := len(adj[onlyNeighbor]) - 1
			for i, other := range adj[onlyNeighbor] {
				if curr == other {
					// replace with element at the end
					adj[onlyNeighbor][i] = adj[onlyNeighbor][lastIndex]
					// shrink
					adj[onlyNeighbor] = adj[onlyNeighbor][:lastIndex]
					break
				}
			}
			// if the neighbor has only 1 left, it is now a leave itself
			if len(adj[onlyNeighbor]) == 1 {
				newLeaves = append(newLeaves, onlyNeighbor)
			}
		}
		// repeat for the next set of leaves
		leaves = newLeaves
	}

	return leaves
}