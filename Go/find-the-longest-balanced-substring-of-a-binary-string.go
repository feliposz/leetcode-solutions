func findTheLongestBalancedSubstring(s string) int {
	var longest, zeros, ones int
	for _, c := range s {
		if c == '0' {
            if ones > 0 {
                zeros, ones = 1, 0
            } else {
			    zeros++
            }
		} else {
			ones++
			if ones <= zeros && 2*ones > longest {
				longest = 2 * ones
			}
		}
	}
	return longest
}