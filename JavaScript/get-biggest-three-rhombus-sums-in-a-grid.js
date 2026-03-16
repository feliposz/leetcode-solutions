/**
 * @param {number[][]} grid
 * @return {number[]}
 */
var getBiggestThree = function (grid) {
    const m = grid.length
    const n = grid[0].length
    const sums = new Set()
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            sums.add(grid[i][j])
            for (let sz = 1; ; sz++) {
                if (i + 2 * sz >= m || j - sz < 0 || j + sz >= n) {
                    break
                }
                let sum = 0
                let ai = i
                let aj = j
                let bi = i + sz
                let bj = j - sz
                let ci = i + sz
                let cj = j + sz
                let di = i + 2 * sz
                let dj = j
                for (let k = 0; k < sz; k++) {
                    sum += grid[ai++][aj++]
                    sum += grid[bi--][bj++]
                    sum += grid[ci++][cj--]
                    sum += grid[di--][dj--]
                }
                sums.add(sum)
            }
        }
    }
    const values = Array.from(sums.values())
    values.sort((a, b) => b - a)
    return values.slice(0, 3)
};