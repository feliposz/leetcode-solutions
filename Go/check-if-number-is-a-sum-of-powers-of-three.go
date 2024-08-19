func checkPowersOfThree(n int) bool {
	for n > 1 {
		if n%3 == 2 {
			return false
		}
		n /= 3
	}
	return n == 1
}