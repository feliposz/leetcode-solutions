/**
 * @param {number[][]} grid
 * @return {boolean}
 */
var canPartitionGrid = function (grid) {
    const m = grid.length
    const n = grid[0].length
    const rowSum = Array(m).fill(0)
    const colSum = Array(n).fill(0)
    let sum = 0
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            const x = grid[i][j]
            rowSum[i] += x
            colSum[j] += x
            sum += x
        }
    }
    if (sum % 2 !== 0) {
        return false
    }
    const target = sum / 2
    let partial = 0
    for (let i = 0; i < m; i++) {
        partial += rowSum[i]
        if (partial === target) {
            return true
        }
    }
    partial = 0
    for (let j = 0; j < n; j++) {
        partial += colSum[j]
        if (partial === target) {
            return true
        }
    }
    return false
};