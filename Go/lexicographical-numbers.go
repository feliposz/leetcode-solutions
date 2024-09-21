func lexicalOrder(n int) []int {
	result := make([]int, n)
	x := 1
	for i := 0; i < n; i++ {
		result[i] = x
		if x*10 <= n {
			x *= 10
		} else {
			for x%10 == 9 || x >= n {
				x /= 10
			}
			x++
		}
	}
	return result
}