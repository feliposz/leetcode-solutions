func checkValid(matrix [][]int) bool {
    n := len(matrix)
    total := 0
    for i := 1; i <= n; i++ {
        total += i * i
    }
    for i := 0; i < n; i++ {
        totalRow, totalCol := 0, 0
        for j := 0; j < n; j++ {
            totalRow += matrix[i][j] * matrix[i][j]
            totalCol += matrix[j][i] * matrix[j][i]
        }
        if total != totalRow || total != totalCol {
            return false
        }
    }
    return true
}