func longestPalindrome(s string) string {
	maxLength, maxStart := 0, 0
	for i := range s {
		for evenOdd := range []int{0, 1} {
			for start, end := i, i+evenOdd; start >= 0 && end < len(s) && s[start] == s[end]; start, end = start-1, end+1 {
				length := end - start + 1
				if maxLength < length {
					maxLength, maxStart = length, start
				}
			}
		}
	}
	return s[maxStart : maxStart+maxLength]
}