/**
 * @param {string} s
 * @param {number} k
 * @return {boolean}
 */
var hasAllCodes = function(s, k) {
    const d = Array(Math.pow(2, k)).fill(false)
    for (let i = 0; i <= s.length - k; i++) {
        d[parseInt(s.substr(i, k), 2)] = true
    }
    for (let x of d) {
        if (!x) {
            return false
        }
    }
    return true
};