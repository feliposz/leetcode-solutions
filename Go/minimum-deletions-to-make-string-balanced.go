func minimumDeletions(s string) int {
	as, bs := 0, 0
	for _, ch := range s {
		if ch == 'a' {
			as++
		}
	}
	result := len(s)
	for _, ch := range s {
		if ch == 'a' {
			as--
		}
		result = min(result, as+bs)
		if ch == 'b' {
			bs++
		}
	}
	return result
}