func compressedString(word string) string {
	out := []rune{}
	prev := rune(word[0])
	count := 0
	for _, c := range word {
		if prev != c || count == 9 {
			out = append(out, rune(count+'0'), prev)
			count = 0
		}
		count++
		prev = c
	}
	out = append(out, rune(count+'0'), prev)
	return string(out)
}