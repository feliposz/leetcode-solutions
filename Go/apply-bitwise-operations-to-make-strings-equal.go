func makeStringsEqual(s string, target string) bool {
	a := strings.ContainsRune(s, '1')
	b := strings.ContainsRune(target, '1')
	return (a || !b) && (!a || b)
}
