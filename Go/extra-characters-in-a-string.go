func minExtraChar(s string, dictionary []string) int {
	n := len(s)
	set := map[string]bool{}
	for _, d := range dictionary {
		set[d] = true
	}
	dp := make([]int, len(s)+1)
	for start := n - 1; start >= 0; start-- {
		dp[start] = 1 + dp[start+1]
		for end := start; end < n; end++ {
			curr := s[start : end+1]
            // fmt.Println(start, end, curr, dp)
			if _, found := set[curr]; found {
				dp[start] = min(dp[start], dp[end+1])
			}
		}
	}
    // fmt.Println(dp)
	return dp[0]
}
