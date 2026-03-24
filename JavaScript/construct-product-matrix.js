/**
 * @param {number[][]} grid
 * @return {number[][]}
 */
var constructProductMatrix = function (grid) {
    const MOD = 12345
    const m = grid.length
    const n = grid[0].length
    const p = Array.from({ length: m }, () => Array(n).fill(0))
    let prevPrefix = 1
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            p[i][j] = prevPrefix
            prevPrefix = (prevPrefix * grid[i][j]) % MOD
        }
    }
    let prevSuffix = 1
    for (let i = m - 1; i >= 0; i--) {
        for (let j = n - 1; j >= 0; j--) {
            p[i][j] = (p[i][j] * prevSuffix) % MOD
            prevSuffix = (prevSuffix * grid[i][j]) % MOD
        }
    }
    return p
};

/**
 * @param {number[][]} grid
 * @return {number[][]}
 */
var constructProductMatrix_arrays = function (grid) {
    const MOD = 12345
    const m = grid.length
    const n = grid[0].length
    const p = Array.from({ length: m }, () => Array(n).fill(0))
    const prefix = Array.from({ length: m }, () => Array(n).fill(0))
    const suffix = Array.from({ length: m }, () => Array(n).fill(0))
    let prevPrefix = 1
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            prefix[i][j] = prevPrefix
            prevPrefix = prevPrefix * grid[i][j] % MOD
        }
    }
    let prevSuffix = 1
    for (let i = m - 1; i >= 0; i--) {
        for (let j = n - 1; j >= 0; j--) {
            suffix[i][j] = prevSuffix
            prevSuffix = prevSuffix * grid[i][j] % MOD
        }
    }
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            p[i][j] = prefix[i][j] * suffix[i][j] % MOD
        }
    }
    return p
};