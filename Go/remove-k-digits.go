func removeKdigits(num string, k int) string {
	if k == len(num) {
		return "0"
	}
	digits := []byte(num)
	for i := 0; i < len(digits)-1; i++ {
		if digits[i] > digits[i+1] {
			digits = slices.Delete(digits, i, i+1)
            i = max(-1, i - 2)
			k--
			if k == 0 {
				break
			}
		}
	}
	if k > 0 {
		for i := len(digits) - 1; i > 0; i-- {
			if digits[i] < digits[i-1] {
				digits = slices.Delete(digits, i-1, i)
				k--
				if k == 0 {
					break
				}
			}
		}
	}
    if k > 0 {
        digits = digits[:len(digits)-k]
    }
	for len(digits) > 0 && digits[0] == '0' {
		digits = digits[1:]
	}
	if len(digits) == 0 {
		return "0"
	}
	return string(digits)
}