func minChanges(s string) int {
	count := 0
	for i := 0; i < len(s); i += 2 {
		if s[i] != s[i+1] {
			count++
		}
	}
	return count
}