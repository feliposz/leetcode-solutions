/**
 * @param {string} s
 * @return {number}
 */
var countBinarySubstrings = function(s) {
    let zeros = 0
    let ones = 0
    let prev = '?'
    let count = 0
    for (let i = 0; i < s.length; i++) {
        const curr = s[i]
        if (curr === '0') {
            if (curr == prev) {
                zeros++            
            } else {
                zeros = 1
            }
            if (zeros <= ones) {
                count++
            }
        } else {
           if (curr == prev) {
                ones++            
            } else {
                ones = 1
            }
            if (ones <= zeros) {
                count++
            }
        }
        prev = curr
    }
    return count
};