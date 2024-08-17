func maxPoints(points [][]int) int64 {
	rows, cols := len(points), len(points[0])
	dp := make([][]int64, rows)
	for i := range dp {
		dp[i] = make([]int64, cols)
	}
	for i := range points[0] {
		dp[0][i] = int64(points[0][i])
	}
	leftMax := make([]int64, cols)
	rightMax := make([]int64, cols)
	for i := 1; i < rows; i++ {
		leftMax[0] = dp[i-1][0]
		rightMax[cols-1] = dp[i-1][cols-1]
		for j := 1; j < cols; j++ {
			leftMax[j] = max(dp[i-1][j], leftMax[j-1]-1)
		}
		for j := cols - 2; j >= 0; j-- {
			rightMax[j] = max(dp[i-1][j], rightMax[j+1]-1)
		}
		for j := range points[i] {
			dp[i][j] = max(leftMax[j], rightMax[j]) + int64(points[i][j])
		}
	}
	ans := int64(0)
	for i := range dp[rows-1] {
		ans = max(ans, dp[rows-1][i])
	}
	return ans
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}