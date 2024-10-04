func alternateDigitSum(n int) int {
	sign := 1
	sum := 0
	for _, d := range strconv.Itoa(n) {
		sum += int(d-'0') * sign
		sign = -sign
	}
	return sum
}