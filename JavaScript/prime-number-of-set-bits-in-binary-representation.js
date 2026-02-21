/**
 * @param {number} left
 * @param {number} right
 * @return {number}
 */
var countPrimeSetBits = function(left, right) {
    let count = 0
    for (let i = left; i <= right; i++) {
        let bits = 0
        for (let shift = i; shift > 0; shift >>= 1) {
            bits += shift & 1
        }
        if (bits === 2 || bits === 3 || bits === 5 || bits === 7 || bits === 11 || bits === 13 || bits === 17 || bits === 19 || bits === 23 || bits === 29 || bits === 31) {
            count++
        }
    }
    return count
};