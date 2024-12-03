func addSpaces(s string, spaces []int) string {
	out := make([]rune, 0, len(s)+len(spaces))
	slices.Sort(spaces)
	curr := 0
	for i, c := range s {
		if curr < len(spaces) && spaces[curr] == i {
			out = append(out, ' ')
			curr++
		}
		out = append(out, c)
	}
	return string(out)
}