func checkValidString(s string) bool {
	// check from left to right and consider * always as (
	open := 0
	for i := 0; i < len(s); i++ {
		if s[i] == '(' || s[i] == '*' {
			open++
		} else {
			open--
			if open < 0 {
				// too many ')'
				return false
			}
		}
	}

	// all balanced, early return
	if open == 0 {
		return true
	}

	// check from right to left and consider * always as )
	open = 0
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == ')' || s[i] == '*' {
			open++
		} else {
			open--
			if open < 0 {
				// too many '('
				return false
			}
		}
	}

	// no invalid condition found
	return true
}