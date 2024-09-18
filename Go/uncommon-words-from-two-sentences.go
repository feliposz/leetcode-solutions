func uncommonFromSentences(s1 string, s2 string) []string {
	words := map[string]int{}
	for _, w := range strings.Fields(s1) {
		words[w]++
	}
	for _, w := range strings.Fields(s2) {
		words[w]++
	}
	result := []string{}
	for w, c := range words {
		if c == 1 {
			result = append(result, w)
		}
	}
	return result
}