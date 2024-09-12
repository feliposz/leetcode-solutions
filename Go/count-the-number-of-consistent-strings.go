func countConsistentStrings(allowed string, words []string) int {
	a := [26]bool{}
	for _, c := range allowed {
		a[c-'a'] = true
	}
	count := 0
outer:
	for _, w := range words {
		for _, c := range w {
			if !a[c-'a'] {
				continue outer
			}
		}
		count++
	}
	return count
}