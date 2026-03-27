/**
 * @param {number[][]} mat
 * @param {number} k
 * @return {boolean}
 */
var areSimilar = function (mat, k) {
    const m = mat.length
    const n = mat[0].length
    k %= n
    if (k == 0) {
        return true
    }
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            const x = (j + k) % n
            if (mat[i][j] !== mat[i][x]) {
                return false
            }
        }
    }
    return true
};