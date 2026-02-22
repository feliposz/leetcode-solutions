/**
 * @param {number} n
 * @return {number}
 */
var binaryGap = function(n) {
    let max = 0
    let gap = 0
    while (n > 0) {
        const bit = n & 1
        if (bit === 1) {
            max = Math.max(max, gap)
            gap = 1
        } else if (gap !== 0) {
            gap++
        }
        n >>= 1
    }
    return max
};