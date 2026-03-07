/**
 * @param {string} s
 * @return {boolean}
 */
var checkOnesSegment = function(s) {
    let first = true
    for (let c of s) {
        if (c === '1' && !first) {
            return false
        } else if (c === '0') {
            first = false
        }
    }
    return true
};