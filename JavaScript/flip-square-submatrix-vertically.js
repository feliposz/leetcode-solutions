/**
 * @param {number[][]} grid
 * @param {number} x
 * @param {number} y
 * @param {number} k
 * @return {number[][]}
 */
var reverseSubmatrix = function (grid, x, y, k) {
    for (let i = 0; i < k; i++) {
        const r1 = x + i
        const r2 = x + k - 1 - i
        if (r1 >= r2) break
        for (let j = y; j < y + k; j++) {
            const tmp = grid[r1][j]
            grid[r1][j] = grid[r2][j]
            grid[r2][j] = tmp
        }
    }
    return grid
};