func numberOfSubstrings(s string) int {
	count := [3]int{}
	ans := 0
	size := 0
	right := 0
	for _, c := range s {
		count[c-'a']++
		for right < len(s) && count[0] > 0 && count[1] > 0 && count[2] > 0 {
			count[s[right]-'a']--
			right++
			size++
		}
		ans += size
	}
	return ans
}