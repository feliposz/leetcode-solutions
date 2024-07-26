func findTheCity(n int, edges [][]int, distanceThreshold int) int {

	// make adjacency matrix with a default very large weight
	adj := make([][]int, n)
	for i := range adj {
		adj[i] = make([]int, n)
		for j := range adj[i] {
			adj[i][j] = 1000000
		}
	}

	// fill the matrix with edges data
	for _, e := range edges {
		adj[e[0]][e[0]] = 0
		adj[e[1]][e[1]] = 0
		adj[e[0]][e[1]] = e[2]
		adj[e[1]][e[0]] = e[2]
	}

	// update distance if distance from i=>k=>j is smaller than i=>j
	for k := range adj {
		for i := range adj {
			for j := range adj[i] {
				if adj[i][j] > adj[i][k]+adj[k][j] {
					adj[i][j] = adj[i][k] + adj[k][j]
				}
			}
		}
	}

	// check each city against other cities within distanceThreshold

	minNeighborsCount := 1000000
	maxNeighborCity := 0

	for i := range adj {
		neighbors := 0
		for j, dist := range adj[i] {
			if i != j && dist <= distanceThreshold {
				neighbors++
			}
		}
		if neighbors <= minNeighborsCount {
			minNeighborsCount = neighbors
			maxNeighborCity = i
		}
	}

	return maxNeighborCity
}
