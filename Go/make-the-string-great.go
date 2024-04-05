func makeGood(s string) string {
	changed := true
	tmp := make([]byte, 0, len(s))
	for changed {
		changed = false
		for i := 0; i < len(s); i++ {
			if i < len(s)-1 && (s[i]-'a' == s[i+1]-'A' || s[i]-'A' == s[i+1]-'a') {
				i++
				changed = true
			} else {
				tmp = append(tmp, s[i])
			}
		}
		s = string(tmp)
		tmp = tmp[:0]
	}
	return s
}