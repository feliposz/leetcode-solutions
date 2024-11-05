func isCircularSentence(sentence string) bool {
	words := strings.Split(sentence, " ")
	n := len(words)
	for i := 0; i < n; i++ {
		j := (i + 1) % n
		if words[i][len(words[i])-1] != words[j][0] {
			return false
		}
	}
	return true
}