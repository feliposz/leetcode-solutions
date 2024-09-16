func findTheLongestSubstring(s string) int {
	vowels := 0
	prefix := [32]int{}
    for i := range prefix {
        prefix[i] = -1
    }
	longest := 0
	for i, c := range s {
		switch c {
		case 'a':
			vowels ^= 1
		case 'e':
			vowels ^= 2
		case 'i':
			vowels ^= 4
		case 'o':
			vowels ^= 8
		case 'u':
			vowels ^= 16
		}
		if prefix[vowels] == -1 && vowels != 0 {
			prefix[vowels] = i
		}
        longest = max(longest, i-prefix[vowels])
	}
	return longest
}