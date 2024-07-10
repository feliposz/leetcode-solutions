func minOperations(logs []string) int {
	level := 0
	for _, d := range logs {
		if d == "../" {
			if level > 0 {
				level--
			}
		} else if d != "./" {
			level++
		}
	}
	return level
}