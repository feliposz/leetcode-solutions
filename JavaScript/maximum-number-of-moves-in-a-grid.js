/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxMoves = function(grid) {
    let m = grid.length
    let n = grid[0].length
    let max = 0

    const cache = {}

    var search = function(row, col) {
        if (col >= n - 1) {
            return 0
        }
        const k = [row,col]
        if (cache[k] == undefined) {
            let res = 0
            if (grid[row][col] < grid[row][col + 1]) {
                res = 1 + search(row, col + 1)
            }
            if (row > 0 && grid[row][col] < grid[row - 1][col + 1]) {
                res = Math.max(res, 1 + search(row - 1, col + 1))
            }
            if (row < m - 1 && grid[row][col] < grid[row + 1][col + 1]) {
                res = Math.max(res, 1 + search(row + 1, col + 1))
            }
            cache[k] = res
        }
        return cache[k]
    }

    for (let row = 0; row < m; row++) {
        max = Math.max(max, search(row, 0))
    }
    return max
};