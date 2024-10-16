func longestDiverseString(a int, b int, c int) string {
	ca, cb, cc := 0, 0, 0
	total := a + b + c
	ans := make([]rune, 0, total)
	for i := 0; i < total; i++ {
		if (a >= b && a >= c && ca < 2) || (a > 0 && (cb == 2 || cc == 2)) {
			ans = append(ans, 'a')
			a--
			ca, cb, cc = ca+1, 0, 0
		} else if (b >= a && b >= c && cb < 2) || (b > 0 && (ca == 2 || cc == 2)) {
			ans = append(ans, 'b')
			b--
			ca, cb, cc = 0, cb+1, 0
		} else if (c >= b && c >= a && cc < 2) || (c > 0 && (ca == 2 || cb == 2)) {
			ans = append(ans, 'c')
			c--
			ca, cb, cc = 0, 0, cc+1
		} else {
			break
		}
	}
	return string(ans)
}