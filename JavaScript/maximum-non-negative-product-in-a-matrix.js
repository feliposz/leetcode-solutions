/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxProductPath = function (grid) {
    const modulo = 1000000007
    const m = grid.length
    const n = grid[0].length
    const max = Array.from({ length: m }, () => Array(n).fill(0))
    const min = Array.from({ length: m }, () => Array(n).fill(0))
    max[0][0] = min[0][0] = grid[0][0]
    for (let i = 1; i < m; i++) {
        max[i][0] = min[i][0] = max[i - 1][0] * grid[i][0]
    }
    for (let j = 1; j < n; j++) {
        max[0][j] = min[0][j] = max[0][j - 1] * grid[0][j]
    }
    for (let i = 1; i < m; i++) {
        for (let j = 1; j < n; j++) {
            const a = grid[i][j] * max[i][j - 1]
            const b = grid[i][j] * max[i - 1][j]
            const c = grid[i][j] * min[i][j - 1]
            const d = grid[i][j] * min[i - 1][j]
            max[i][j] = Math.max(a, b, c, d)
            min[i][j] = Math.min(a, b, c, d)
        }
    }
    const result = max[m - 1][n - 1] % modulo
    return Math.max(-1, result)
};

/**
* @param {number[][]} grid
* @return {number}
*/
var maxProductPath_TLE = function (grid) {
    const modulo = 1000000007
    const m = grid.length
    const n = grid[0].length
    const helper = function (i, j, prod) {
        if (i === m - 1 && j === n - 1) {
            return prod
        }
        let right = -1
        let down = -1
        if (i < m - 1) {
            down = helper(i + 1, j, prod * grid[i + 1][j])
        }
        if (j < n - 1) {
            right = helper(i, j + 1, prod * grid[i][j + 1])
        }
        return Math.max(right, down)
    }
    return Math.max(-1, helper(0, 0, grid[0][0]) % modulo)
};