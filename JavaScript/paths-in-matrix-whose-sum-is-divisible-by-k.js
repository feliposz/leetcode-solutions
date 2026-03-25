/**
 * @param {number[][]} grid
 * @param {number} k
 * @return {number}
 */
var numberOfPaths_v2 = function (grid, k) {
    const MOD = 1000000007
    const m = grid.length
    const n = grid[0].length
    let count = 0
    const paths = Array.from({ length: m }, () => Array.from({ length: n }, () => Array(k).fill(0)))
    const rem = grid[0][0] % k
    paths[0][0][rem] = 1
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            for (let rem = 0; rem < k; rem++) {
                const count = paths[i][j][rem]
                if (count === 0) {
                    continue
                }
                if (i < m - 1) { // moving down
                    const nextRem = (rem + grid[i + 1][j]) % k
                    paths[i + 1][j][nextRem] = (paths[i + 1][j][nextRem] + count) % MOD
                }
                if (j < n - 1) { // moving right
                    const nextRem = (rem + grid[i][j + 1]) % k
                    paths[i][j + 1][nextRem] = (paths[i][j + 1][nextRem] + count) % MOD
                }
            }
        }
    }
    return paths[m - 1][n - 1][0]
};

var numberOfPaths_v1 = function (grid, k) {
    const MOD = 1000000007
    const m = grid.length
    const n = grid[0].length
    let count = 0
    const paths = Array.from({ length: m }, () => Array.from({ length: n }, () => Array(k).fill(0)))
    const rem = grid[0][0] % k
    paths[0][0][rem] = 1
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            for (let x = 0; x < k; x++) {
                if (i > 0) {
                    const left = paths[i - 1][j][x]
                    if (left !== 0) {
                        const rem = (x + grid[i][j]) % k
                        paths[i][j][rem] = (paths[i][j][rem] + left) % MOD
                    }
                }
                if (j > 0) {
                    const up = paths[i][j - 1][x]
                    if (up !== 0) {
                        const rem = (x + grid[i][j]) % k
                        paths[i][j][rem] = (paths[i][j][rem] + up) % MOD
                    }
                }
            }
        }
    }
    return paths[m - 1][n - 1][0]
};

var numberOfPaths_TLE = function (grid, k) {
    const MOD = 1000000007
    const m = grid.length
    const n = grid[0].length
    let count = 0
    var helper = function (i, j, acc) {
        acc = (acc + grid[i][j]) % k
        if (i === m - 1 && j === n - 1 && acc === 0) {
            count = (count + 1) % MOD
            return
        }
        if (i < m - 1) {
            helper(i + 1, j, acc)
        }
        if (j < n - 1) {
            helper(i, j + 1, acc)
        }
    }
    helper(0, 0, 0)
    return count
};

var numberOfPaths = numberOfPaths_v1