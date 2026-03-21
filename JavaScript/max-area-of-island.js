/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxAreaOfIsland = function (grid) {
    const m = grid.length
    const n = grid[0].length
    let max = 0
    var calcArea = function (r, c) {
        if (r < 0 || c < 0 || r >= m || c >= n) {
            return 0
        }
        if (grid[r][c] === 0) {
            return 0
        }
        grid[r][c] = 0
        return 1 + calcArea(r - 1, c) + calcArea(r + 1, c) +
            calcArea(r, c - 1) + calcArea(r, c + 1)
    }
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            const area = calcArea(i, j)
            max = Math.max(max, area)
        }
    }
    return max
};