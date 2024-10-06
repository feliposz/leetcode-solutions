func areSentencesSimilar(sentence1 string, sentence2 string) bool {
	w1 := strings.Split(sentence1, " ")
	w2 := strings.Split(sentence2, " ")
	for len(w1) > 0 && len(w2) > 0 && w1[0] == w2[0] {
		w1, w2 = w1[1:], w2[1:]
	}
	for i, j := len(w1)-1, len(w2)-1; i >= 0 && j >= 0 && w1[i] == w2[j]; i, j = i-1, j-1 {
		w1, w2 = w1[:i], w2[:j]
	}
	return len(w1) == 0 || len(w2) == 0
}