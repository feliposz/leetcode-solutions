/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    const n = arr.length
    const result = []
    for (let i = 0; i < n; i++) {
        if (fn(arr[i], i)) {
            result.push(arr[i])
        }
    }
    return result
};