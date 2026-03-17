/**
 * @param {number[][]} matrix
 * @return {number}
 */
var largestSubmatrix = function (matrix) {
    const m = matrix.length
    const n = matrix[0].length
    for (let j = 0; j < n; j++) {
        let count = 0
        for (let i = 0; i < m; i++) {
            if (matrix[i][j] === 0) {
                count = 0
            } else {
                count++
                matrix[i][j] = count
            }
        }
    }
    let result = 0
    for (let i = 0; i < m; i++) {
        matrix[i].sort((a, b) => b - a)
        for (let j = 0; j < n && matrix[i][j] > 0; j++) {
            const width = j + 1
            const height = matrix[i][j]
            result = Math.max(result, width * height)
        }
    }
    return result
};