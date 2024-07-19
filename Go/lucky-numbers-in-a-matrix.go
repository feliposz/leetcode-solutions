func luckyNumbers (matrix [][]int) []int {
    m, n := len(matrix), len(matrix[0])
    minRow := make([]int, m)
    maxCol := make([]int, n)
    for i := range minRow {
        minRow[i] = 1000000
    }
    for i := range maxCol {
        maxCol[i] = -1000000
    }
    for i := range matrix {
        for j, x := range matrix[i] {
            minRow[i] = min(minRow[i], x)
            maxCol[j] = max(maxCol[j], x)
        }
    }
    ans := []int{}
    for i := range matrix {
        for j, x := range matrix[i] {
            if x == minRow[i] && x == maxCol[j] {
                ans = append(ans, x)
            }
        }
    }
    return ans
}