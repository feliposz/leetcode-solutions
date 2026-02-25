/**
 * @param {number[]} arr
 * @return {number[]}
 */
var sortByBits = function (arr) {
    arr.sort((a, b) => {
        let ca = 0, cb = 0
        for (let x = a; x > 0; x >>= 1) {
            ca += x & 1
        }
        for (let x = b; x > 0; x >>= 1) {
            cb += x & 1
        }
        if (ca == cb) {
            return a - b
        } else {
            return ca - cb
        }
    })
    return arr
};