func rotateString(s string, goal string) bool {
	n := len(s)
	if n != len(goal) {
		return false
	}
	for i := 0; i < n; i++ {
		match := true
		for j := 0; j < n; j++ {
			if s[j] != goal[(i+j)%n] {
				match = false
				break
			}
		}
		if match {
			return true
		}
	}
	return false
}