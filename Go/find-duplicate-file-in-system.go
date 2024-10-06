func findDuplicate(paths []string) [][]string {
	m := map[string][]string{}
	for _, p := range paths {
		parts := strings.Split(p, " ")
		root := parts[0]
		for _, f := range parts[1:] {
			comps := strings.Split(f, "(")
			name := root + "/" + comps[0]
			content := comps[1][:len(comps[1])-1]
			m[content] = append(m[content], name)
		}
	}
	res := [][]string{}
	for _, files := range m {
		if len(files) > 1 {
			res = append(res, files)
		}
	}
	return res
}