func maximumLengthSubstring(s string) int {
	var freq [26]int
	maxLength := 0
	i, j, n := 0, 0, len(s)
	for j < n {
		c := s[j] - 'a'
		j++
		freq[c]++
		for i <= j && freq[c] > 2 {
			d := s[i] - 'a'
			freq[d]--
			i++
		}
		maxLength = max(maxLength, j-i)
	}
	return maxLength
}