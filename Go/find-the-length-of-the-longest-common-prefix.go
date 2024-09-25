func longestCommonPrefix(arr1 []int, arr2 []int) int {
	longest := 0
	prefixes := map[int]bool{}
	for _, x := range arr1 {
		for x > 0 {
			prefixes[x] = true
			x /= 10
		}
	}
	for _, x := range arr2 {
		for x > 0 {
			if prefixes[x] {
				longest = max(longest, x)
			}
			x /= 10
		}
	}
    if longest == 0 {
        return 0
    }
	return len(strconv.Itoa(longest))
}