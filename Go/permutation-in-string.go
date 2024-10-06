func checkInclusion(s1 string, s2 string) bool {
	if len(s2) < len(s1) {
		return false
	}
	m1 := [26]int{}
	for _, c := range []byte(s1) {
		m1[c-'a']++
	}
	m2 := [26]int{}
	i := 0
	n := len(s1)
	for i < n-1 {
		m2[s2[i]-'a']++
		i++
	}
	for i < len(s2) {
		m2[s2[i]-'a']++
		if m1 == m2 {
			return true
		}
		i++
		m2[s2[i-n]-'a']--
	}
	return false
}