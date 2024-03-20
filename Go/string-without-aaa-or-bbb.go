func strWithout3a3b(a int, b int) string {
	result := make([]byte, 0, a+b)
	for a > 0 && b > 0 && a != b {
        if a > b {
            result = append(result, 'a', 'a', 'b')
            a -= 2
            b--
        } else {
            result = append(result, 'b', 'b', 'a')
            b -= 2
            a--
        }
    }
    for a > 0 || b > 0 {
        if a > 0 {
            result = append(result, 'a')
            a--
        }
        if b > 0 {
            result = append(result, 'b')
            b--
        }
    }
	return string(result)
}