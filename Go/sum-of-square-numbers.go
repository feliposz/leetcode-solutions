func judgeSquareSum(c int) bool {
	a, b := 0, int(math.Sqrt(float64(c)))
	for a <= b {
		x := a*a + b*b
		if x < c {
			a++
		} else if x > c {
			b--
		} else {
			return true
		}
	}
	return false
}