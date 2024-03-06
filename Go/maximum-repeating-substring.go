func maxRepeating(sequence string, word string) int {
	maxCount := 0
	wordLen := len(word)
	for {
		pos := strings.Index(sequence, word)
		if pos == -1 {
			break
		}
		count := 1
		other := pos + wordLen
		for other+wordLen <= len(sequence) && word == sequence[other:other+wordLen] {
			other += wordLen
			count++
		}
		if maxCount < count {
			maxCount = count
		}
		sequence = sequence[pos+1:]
	}
	return maxCount
}