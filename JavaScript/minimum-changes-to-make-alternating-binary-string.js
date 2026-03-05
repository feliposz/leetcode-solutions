/**
 * @param {string} s
 * @return {number}
 */
var minOperations = function (s) {
    let a = 0
    let b = 0
    for (let i = 0; i < s.length; i++) {
        if ((s.charCodeAt(i) & 1) != (i & 1)) {
            a++
        } else {
            b++
        }
    }
    return Math.min(a, b)
};