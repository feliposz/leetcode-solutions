func isSubstringPresent(s string) bool {
    n := len(s)
    for i := 0; i < n - 1; i++ {
        sub := string([]byte{s[i+1], s[i]})
		if strings.Contains(s, sub) {
			return true
		}
    }
	return false
}