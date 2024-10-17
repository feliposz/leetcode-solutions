func maximumSwap(num int) int {
	digits := []byte(strconv.Itoa(num))
	i, j := 0, 0
	maxIndex := len(digits) - 1
	max := digits[maxIndex]
	for k := maxIndex; k >= 0; k-- {
		if max < digits[k] {
			max = digits[k]
			maxIndex = k
		} else if max > digits[k] {
			i, j = maxIndex, k
		}
	}
	if i != j {
		digits[i], digits[j] = digits[j], digits[i]
	}
	ans, _ := strconv.Atoi(string(digits))
	return ans
}