func maximalRectangle(matrix [][]byte) int {
    m, n := len(matrix), len(matrix[0])
    tmp := make([]byte, n)
    maxArea := 0
    for i := 0; i < m; i++ {
        for k := 0; k < n; k++ {
            tmp[k] = 1
        }
        for j := i; j < m; j++ {
            width, maxWidth := 0, 0
            for k, value := range matrix[j] {
                tmp[k] &= value
                if tmp[k] == 0 {
                    width = 0
                } else {
                    width++
                    maxWidth = max(maxWidth, width)
                }
            }
            maxArea = max(maxArea, (j - i + 1) * maxWidth)
        }
    }
    return maxArea
}