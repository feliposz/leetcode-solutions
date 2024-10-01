func checkIfCanBreak(s1 string, s2 string) bool {
	b1 := []byte(s1)
	b2 := []byte(s2)
	slices.Sort(b1)
	slices.Sort(b2)
	m, n := true, true
	for i := range b1 {
		if b1[i] < b2[i] {
			m = false
		}
		if b2[i] < b1[i] {
			n = false
		}
	}
	return m || n
}