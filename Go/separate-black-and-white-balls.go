func minimumSteps(s string) int64 {
	zeros := 0
	steps := int64(0)
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == '0' {
			zeros++
		} else {
			steps += int64(zeros)
		}
	}
	return steps
}