func lengthOfLastWord(s string) int {
	s = strings.TrimRight(s, " ")
	i := strings.LastIndex(s, " ")
	if i == -1 {
		return len(s)
	}
	return len(s) - i - 1
}