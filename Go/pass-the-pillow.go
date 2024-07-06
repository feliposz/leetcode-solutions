func passThePillow(n int, time int) int {
	p := time % (n - 1)
	r := time / (n - 1)
	if r%2 == 0 {
		return p + 1
	}
	return n - p
}