func minDistance(word1 string, word2 string) int {
	m := make([][]int, len(word1)+1)
	for i := range m {
		m[i] = make([]int, len(word2)+1)
		m[i][0] = i
	}
	for j := range m[0] {
		m[0][j] = j
	}
	for i, a := range word1 {
		for j, b := range word2 {
			if a == b {
				m[i+1][j+1] = m[i][j]
			} else {
				m[i+1][j+1] = min(m[i][j+1], m[i+1][j], m[i][j]) + 1
			}
		}
	}
	return m[len(m)-1][len(m[0])-1]
}