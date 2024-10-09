func minSwaps(s string) int {
	open := 0
	for _, c := range s {
		if c == '[' {
			open++
		} else if open > 0 {
			open--
		}
	}
	return (open + 1) / 2
}