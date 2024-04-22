func openLock(deadends []string, target string) int {

	visited := map[string]bool{}
	for _, d := range deadends {
		if d == "0000" {
			return -1
		}
		visited[d] = true
	}

	queue := []queueEntry{queueEntry{"0000", 0}}
	visited["0000"] = true

	for len(queue) > 0 {
		curr := queue[0]
		queue = queue[1:]
		if curr.comb == target {
			return curr.steps
		}
		neighbors := possibleMoves(curr.comb)
		for _, neighbor := range neighbors {
			if !visited[neighbor] {
				visited[neighbor] = true
				queue = append(queue, queueEntry{neighbor, curr.steps + 1})
			}
		}
	}

	return -1
}

type queueEntry struct {
	comb  string
	steps int
}

func possibleMoves(curr string) []string {
	candidates := []string{}
	for _, dir := range []int{1, -1} {
		for i := range curr {
			digits := []byte(curr)
			digits[i] = byte(int(digits[i]) + dir)
			if digits[i] < '0' {
				digits[i] = '9'
			} else if digits[i] > '9' {
				digits[i] = '0'
			}
			candidates = append(candidates, string(digits))
		}
	}
	return candidates
}

