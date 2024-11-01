func makeFancyString(s string) string {
	out := []rune{}
	for _, c := range s {
		n := len(out)
		if n >= 2 && c == out[n-1] && c == out[n-2] {
			continue
		}
		out = append(out, c)
	}
	return string(out)
}