func maximumValue(strs []string) int {
	ans := 0
	for _, s := range strs {
		value := 0
		for _, c := range s {
			if c >= '0' && c <= '9' {
				value = value*10 + int(c - '0')
			} else {
				value = len(s)
				break
			}
		}
		ans = max(ans, value)
	}
	return ans
}