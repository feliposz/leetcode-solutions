func restoreMatrix(rowSum []int, colSum []int) [][]int {
	ans := make([][]int, len(rowSum))
	for i := range ans {
		ans[i] = make([]int, len(colSum))
	}
	for i := range ans {
		for j := range ans[i] {
			ans[i][j] = min(rowSum[i], colSum[j])
			rowSum[i] -= ans[i][j]
			colSum[j] -= ans[i][j]
		}
	}
	return ans
}

func NAIVE_restoreMatrix(rowSum []int, colSum []int) [][]int {
	ans := make([][]int, len(rowSum))
	for i := range ans {
		ans[i] = make([]int, len(colSum))
	}
	for {
		x := 999999999
		row, col := -1, -1
		for r, s := range rowSum {
			if s > 0 && x > s {
				row = r
				x = s
			}
		}
		for c, s := range colSum {
			if s > 0 && x > s {
				col = c
				row = -1
				x = s
			}
		}
		if col != -1 {
			for r := range ans {
				if rowSum[r] >= x && ans[r][col] == 0 {
					ans[r][col] = x
					colSum[col] = 0
					rowSum[r] -= x
					break
				}
			}
		} else if row != -1 {
			for c := range ans[row] {
				if colSum[c] >= x && ans[row][c] == 0 {
					ans[row][c] = x
					colSum[c] -= x
					rowSum[row] = 0
					break
				}
			}
		} else {
			break
		}
	}
	return ans
}