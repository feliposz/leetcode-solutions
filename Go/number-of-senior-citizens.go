func countSeniors(details []string) int {
	count := 0
	for _, d := range details {
		age := int(d[11]-'0')*10 + int(d[12]-'0')
		if age > 60 {
			count++
		}
	}
	return count
}