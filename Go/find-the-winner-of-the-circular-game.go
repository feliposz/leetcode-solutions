func findTheWinner(n int, k int) int {
	p := make([]int, n)
	for i := range p {
		p[i] = i + 1
	}

	x := 0
	for len(p) > 1 {
		x = (x + k - 1) % len(p)
		p = slices.Delete(p, x, x+1)
	}

	return p[0]
}