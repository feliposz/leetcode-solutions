func removeStones(stones [][]int) int {
	points := map[pair]struct{}{}
	rows := map[int][]int{}
	cols := map[int][]int{}

	for _, stone := range stones {
		i, j := stone[0], stone[1]
		points[pair{i, j}] = struct{}{}
		rows[i] = append(rows[i], j)
		cols[j] = append(cols[j], i)
	}

	var dfs func(i, j int)
	dfs = func(i, j int) {
		delete(points, pair{i, j})
		for _, y := range rows[i] {
			if _, ok := points[pair{i, y}]; ok {
				dfs(i, y)
			}
		}
		for _, x := range cols[j] {
			if _, ok := points[pair{x, j}]; ok {
				dfs(x, j)
			}
		}
	}

	islands := 0

	for _, stone := range stones {
		i, j := stone[0], stone[1]
		if _, ok := points[pair{i, j}]; ok {
			dfs(i, j)
			islands++
		}
	}

	return len(stones) - islands
}

type pair [2]int