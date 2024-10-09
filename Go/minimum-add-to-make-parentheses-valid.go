func minAddToMakeValid(s string) int {
	balance, mustOpen := 0, 0
	for _, c := range s {
		if c == '(' {
			balance++
		} else if balance > 0 {
			balance--
		} else {
			mustOpen++
		}
	}
	return balance + mustOpen
}