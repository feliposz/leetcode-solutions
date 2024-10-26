func removeSubfolders(folder []string) []string {
	folders := map[string]bool{}
	for _, p := range folder {
		folders[p] = true
	}
	ans := []string{}
	for _, p := range folder {
		parts := strings.Split(p, "/")
		skip := false
		for i := len(parts) - 1; i > 0; i-- {
			test := strings.Join(parts[:i], "/")
			if _, found := folders[test]; found {
				skip = true
				break
			}
		}
		if !skip {
			ans = append(ans, p)
		}
	}
	return ans
}
