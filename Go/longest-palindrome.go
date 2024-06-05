func longestPalindrome(s string) int {
	letters := map[byte]int{}
	for _, c := range []byte(s) {
        letters[c]++
	}
    ones := 0
    size := 0
    for _, count := range letters {
        if count % 2 == 0 {
            size += count
        } else {
            size += count / 2 * 2
            ones++
        }
    }
    if ones > 0 {
        size++
    }
	return size
}