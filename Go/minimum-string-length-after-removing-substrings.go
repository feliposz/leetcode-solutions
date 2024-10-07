func minLength(s string) int {
	stack := []rune{}
	for _, r := range s {
		if r == 'B' && len(stack) > 0 && stack[len(stack)-1] == 'A' {
			stack = stack[:len(stack)-1]
		} else if r == 'D' && len(stack) > 0 && stack[len(stack)-1] == 'C' {
			stack = stack[:len(stack)-1]
		} else {
			stack = append(stack, r)
		}
	}
	return len(stack)
}