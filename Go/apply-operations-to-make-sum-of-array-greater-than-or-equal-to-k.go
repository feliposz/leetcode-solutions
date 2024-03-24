func minOperations(k int) int {
	if k == 1 {
		return 0
	}
	elem := 1
	mult := 1
	x := 0
	op := 0
	for x < k {
		op++
		a := mult * (elem + 1)
		b := (mult + 1) * elem
		if a > b {
			elem++
			x = a
		} else {
			mult++
			x = b
		}
	}
	return op
}